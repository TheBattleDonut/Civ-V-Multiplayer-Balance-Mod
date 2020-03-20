-- FractalPlus
-- Author: TheBattleDonut
-- DateCreated: 3/8/2020 4:13:17 PM
--------------------------------------------------------------
include("MapGenerator");
include("FractalWorld");
include("FeatureGenerator");
include("TerrainGenerator");

function GetMapScriptInfo()
    local world_age, temperature, rainfall, sea_level, resources = GetCoreMapOptions()
	return {
		Name = "Fractal Plus",
		Description = "Fractal + Resources option",
        IconIndex = 5,
        SupportsMultiplayer = true,
        CustomOptions = {sea_level, resources},
	}
end
----------------------------------------------------------------------------------
function GeneratePlotTypes()
	print("Setting Plot Types (Lua Fractal) ...");

	local fractal_world = FractalWorld.Create();
	fractal_world:InitFractal{
		rift_grain = -1,
		has_center_rift = false,
		polar = true};

	local sea_lev = Map.GetCustomOption(1)
	if sea_lev == 4 then
		sea_lev = 1 + Map.Rand(3, "Random Sea Level - Lua");
	end

	local args = {
		sea_level = sea_lev,
		has_center_rift = false
		}
	local plotTypes = fractal_world:GeneratePlotTypes(args);
	
	SetPlotTypes(plotTypes);
	GenerateCoasts();

end
----------------------------------------------------------------------------------
function GenerateTerrain()
	print("Generating Terrain (Lua Fractal) ...");
	
	local terraingen = TerrainGenerator.Create();
	local terrainTypes = terraingen:GenerateTerrain()
		
	SetTerrainTypes(terrainTypes);
end
----------------------------------------------------------------------------------
function AddFeatures()
	print("Adding Features (Lua Fractal) ...");
	
	local featuregen = FeatureGenerator.Create();
	featuregen:AddFeatures();
end
------------------------------------------------------------------------------
function StartPlotSystem()
	-- Get Resources setting input by user.
	local res = Map.GetCustomOption(2)
	if res == 6 then
		res = 1 + Map.Rand(3, "Random Resources Option - Lua");
	end

	print("Creating start plot database.");
	local start_plot_database = AssignStartingPlots.Create()
	
	print("Dividing the map in to Regions.");
	-- Regional Division Default Method: Continental
	local args = {
		resources = res,
		};
	start_plot_database:GenerateRegions(args)

	print("Choosing start locations for civilizations.");
	start_plot_database:ChooseLocations()
	
	print("Normalizing start locations and assigning them to Players.");
	start_plot_database:BalanceAndAssign()

	print("Placing Natural Wonders.");
	start_plot_database:PlaceNaturalWonders()

	print("Placing Resources and City States.");
	start_plot_database:PlaceResourcesAndCityStates()
end
------------------------------------------------------------------------------