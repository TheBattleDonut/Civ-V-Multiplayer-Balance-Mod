-- TODO: Maybe implement a catch to make sure we don't insert a promotion/etc. twice?
-- If you run this SQL twice it will double-add the rows. Whoops.

-- Add the new UNITCOMBAT_PARADROPPER class and update Paratrooper's and XCOM to use it.
INSERT INTO UnitCombatInfos(Type, Description) VALUES('UNITCOMBAT_PARADROPPER', 'TXT_KEY_UNITCOMBAT_PARADROPPER');
INSERT INTO Language_en_US(Tag, Text) VALUES('TXT_KEY_UNITCOMBAT_PARADROPPER', "Paradropping Units" );
UPDATE Units SET CombatClass='UNITCOMBAT_PARADROPPER' WHERE Class='UNITCLASS_PARATROOPER';
UPDATE Units SET CombatClass='UNITCOMBAT_PARADROPPER' WHERE Class='UNITCLASS_XCOM_SQUAD';

-- Same free promotions as for UNITCOMBAT_GUN
INSERT INTO Trait_FreePromotionUnitCombats (TraitType, UnitCombatType, PromotionType)
SELECT TraitType, 'UNITCOMBAT_PARADROPPER', PromotionType
FROM Trait_FreePromotionUnitCombats WHERE UnitCombatType='UNITCOMBAT_GUN';

-- Copy all UnitCombat Mod promotions from the UNITCOMBAT_GUN line
INSERT INTO UnitPromotions_UnitCombatMods (PromotionType, UnitCombatType, Modifier, PediaType)
SELECT PromotionType, 'UNITCOMBAT_PARADROPPER', Modifier, PediaType
FROM UnitPromotions_UnitCombatMods WHERE UnitCombatType='UNITCOMBAT_GUN';

-- Copy all UnitCombat promotions from the UNITCOMBAT_GUN line
INSERT INTO UnitPromotions_UnitCombats (PromotionType, UnitCombatType, PediaType)
SELECT PromotionType, 'UNITCOMBAT_PARADROPPER', PediaType
FROM UnitPromotions_UnitCombats WHERE UnitCombatType='UNITCOMBAT_GUN';

-- Remove the Blitz promotion
DELETE FROM UnitPromotions_UnitCombats WHERE UnitCombatType='UNITCOMBAT_PARADROPPER' AND PromotionType='PROMOTION_BLITZ';