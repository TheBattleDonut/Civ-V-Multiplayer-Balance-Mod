#include "CvGameCoreDLLPCH.h"

#include "LintFree.h"

CustomMods gCustomMods;

CustomMods::CustomMods() {}

int CustomMods::eventHook(const char* szName, const char* p, ...) {
	CvLuaArgsHandle args;

	va_list vl;
	va_start(vl, p);

	for (const char* it = p; *it; ++it) {
		if (*it == 'b') {
			// It's a boolean
			args->Push(va_arg(vl, bool));
		} else if (*it == 'i') {
			// It's an int
			args->Push(va_arg(vl, int));
		} else {
			// Assume it's a string (char *)
			char* s = va_arg(vl, char*);
			args->Push(s, strlen(s));
			break;
		}
	}

	va_end(vl);

	return eventHook(szName, args);
}

int CustomMods::eventTestAll(const char* szName, const char* p, ...) {
	CvLuaArgsHandle args;

	va_list vl;
	va_start(vl, p);

	for (const char* it = p; *it; ++it) {
		if (*it == 'b') {
			// It's a boolean
			args->Push(va_arg(vl, bool));
		} else if (*it == 'i') {
			// It's an int
			args->Push(va_arg(vl, int));
		} else {
			// Assume it's a string (char *)
			char* s = va_arg(vl, char*);
			args->Push(s, strlen(s));
			break;
		}
	}

	va_end(vl);

	return eventTestAll(szName, args);
}

int CustomMods::eventHook(const char* szName, CvLuaArgsHandle &args) {
	ICvEngineScriptSystem1* pkScriptSystem = gDLL->GetScriptSystem();
	if (pkScriptSystem) {
		bool bResult;
		if (LuaSupport::CallHook(pkScriptSystem, szName, args.get(), bResult)) {
			return GAMEEVENTRETURN_HOOK;
		}
	}

	return GAMEEVENTRETURN_NONE;
}

int CustomMods::eventTestAll(const char* szName, CvLuaArgsHandle &args) {
	ICvEngineScriptSystem1* pkScriptSystem = gDLL->GetScriptSystem();
	if (pkScriptSystem) {
		bool bResult = false;
		if (LuaSupport::CallTestAll(pkScriptSystem, szName, args.get(), bResult)) {
			if (bResult) {
				return GAMEEVENTRETURN_TRUE;
			} else {
				return GAMEEVENTRETURN_FALSE;
			}
		}
	}

	return GAMEEVENTRETURN_NONE;
}