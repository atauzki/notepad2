#include "EditLexer.h"
#include "EditStyleX.h"

// https://www.json.org
// https://json5.org/
// https://spec.json5.org/

static KEYWORDLIST Keywords_JSON = {{
//++Autogenerated -- start of section automatically generated
"Infinity NaN false null true "

, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
//--Autogenerated -- end of section automatically generated
}};

static EDITSTYLE Styles_JSON[] = {
	EDITSTYLE_DEFAULT,
	{ SCE_JSON_KEYWORD, NP2StyleX_Keyword, L"fore:#0000FF" },
	{ SCE_JSON_PROPERTYNAME, NP2StyleX_Property, L"fore:#A46000" },
	{ MULTI_STYLE(SCE_JSON_LINECOMMENT, SCE_JSON_BLOCKCOMMENT, 0, 0), NP2StyleX_Comment, L"fore:#608060" },
	{ MULTI_STYLE(SCE_JSON_STRING, SCE_JSON_CHARACTER, 0, 0), NP2StyleX_String, L"fore:#008000" },
	{ SCE_JSON_ESCAPESEQUENCE, NP2StyleX_EscapeSequence, L"fore:#0080C0" },
	{ SCE_JSON_NUMBER, NP2StyleX_Number, L"fore:#FF0000" },
	{ SCE_JSON_OPERATOR, NP2StyleX_Operator, L"fore:#B000B0" },
};

EDITLEXER lexJSON = {
	SCLEX_JSON, NP2LEX_JSON,
//Settings++Autogenerated -- start of section automatically generated
	{
		LexerAttr_Default,
		TAB_WIDTH_4, INDENT_WIDTH_4,
		(1 << 0) | (1 << 1) | (1 << 2) | (1 << 3), // level1, level2, level13, level4
		0
		, KeywordAttr32(0, KeywordAttr_PreSorted) // keywords
	},
//Settings--Autogenerated -- end of section automatically generated
	EDITLEXER_HOLE(L"JSON Document", Styles_JSON),
	L"json; har; ipynb; wxcp; jshintrc; eslintrc; babelrc; prettierrc; stylelintrc; jsonld; jsonc; arcconfig; arclint; jscop",
	&Keywords_JSON,
	Styles_JSON
};
