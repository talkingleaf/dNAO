/*	SCCS Id: @(#)engrave.h	3.4	1991/07/31	*/
/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
/* NetHack may be freely redistributed.  See license for details. */

#ifndef ENGRAVE_H
#define ENGRAVE_H

struct engr {
	struct engr *nxt_engr;
	char *engr_txt;
	xchar engr_x, engr_y;
	unsigned engr_lth;	/* for save & restore; not length of text */
	long engr_time;		/* moment engraving was (will be) finished */
	xchar engr_type;
#define DUST	   1
#define ENGRAVE    2
#define BURN	   3
#define MARK	   4
#define ENGR_BLOOD 5
#define HEADSTONE  6
#define N_ENGRAVE  6
	xchar ward_type;
	int ward_id; /* id number of ward, or of the halucinatory ward if halu_ward is TRUE */
#define HEPTAGRAM					1
#define GORGONEION					2
#define CIRCLE_OF_ACHERON			3
#define PENTAGRAM					4
#define HEXAGRAM					5
#define HAMSA						6
#define ELDER_SIGN					7
#define ELDER_ELEMENTAL_EYE			8
#define SIGN_OF_THE_SCION_QUEEN		9
#define CARTOUCHE_OF_THE_CAT_LORD	10
#define WINGS_OF_GARUDA				11
#define SIGIL_OF_CTHUGHA			12
#define BRAND_OF_ITHAQUA			13
#define TRACERY_OF_KRAKAL			14
#define YELLOW_SIGN					15

#define FIRST_RUNE					16

#define TOUSTEFNA					16
#define DREPRUN						17
#define OTTASTAFUR					18
#define KAUPALOKI					19
#define VEIOISTAFUR					20
#define THJOFASTAFUR				21
#define TH_RUNE						22
#define T_RUNE						23
#define NG_RUNE						24
#define A_RUNE						25

#define NUMBER_OF_WARDS				25
#define LAST_WARD					25

#define FIRST_SEAL					LAST_WARD+1
#define AHAZU						LAST_WARD+1
#define AMON						LAST_WARD+2
#define ANDREALPHUS					LAST_WARD+3
#define ANDROMALIUS					LAST_WARD+4
#define ASTAROTH					LAST_WARD+5
#define BALAM						LAST_WARD+6
#define BERITH						LAST_WARD+7
#define BUER						LAST_WARD+8
#define CHUPOCLOPS					LAST_WARD+9
#define DANTALION					LAST_WARD+10
#define DUNSTAN						LAST_WARD+11
#define ECHIDNA						LAST_WARD+12
#define EDEN						LAST_WARD+13
#define ERIDU						LAST_WARD+14
#define EURYNOME					LAST_WARD+15
#define EVE							LAST_WARD+16
#define FAFNIR						LAST_WARD+17
#define HUGINN_MUNINN				LAST_WARD+18
#define IRIS						LAST_WARD+19
#define JACK						LAST_WARD+20
#define MALPHAS						LAST_WARD+21
#define MARIONETTE					LAST_WARD+22
#define MOTHER						LAST_WARD+23
#define NABERIUS					LAST_WARD+24
#define ORTHOS						LAST_WARD+25
#define OSE							LAST_WARD+26
#define OTIAX						LAST_WARD+27
#define PAIMON						LAST_WARD+28
#define SIMURGH						LAST_WARD+29
#define TENEBROUS					LAST_WARD+30
#define YMIR						LAST_WARD+31
#define DAHLVER_NAR					LAST_WARD+32
#define ACERERAK					LAST_WARD+33
#define NUMINA						LAST_WARD+34

/*Some hallucinatory engravings have special properties. Keep track of them here*/
/*Functional halucinatory wards, keep in sync with engrave.c!*/
#define CERULEAN_SIGN				2
/*These wards move across the ground. Keep in sync with allmain*/
#define	NORTHEAST_GLIDER	3
#define	NORTHWEST_GLIDER	4
#define	SOUTHWEST_GLIDER	5
#define	SOUTHEAST_GLIDER	6
#define DEAD_GLIDER			7
/*These engravings correspond to active drow houses*/
#define BAENRE				8
#define BARRISON_DEL_ARMGO	9
#define XORLARRIN 			10
#define FAEN_TLABBAR 		11
#define MIZZRYM				12
#define FEY_BRANCHE			13
#define MELARN				14
#define DUSKRYN				15
#define FIRST_HOUSE			BAENRE
#define LAST_HOUSE			DUSKRYN
/*These engravings correspond to disbanded drow houses*/
#define BRONT_TEJ			16
#define CELOFRAIE			17
#define DEVIR				18
#define DO_URDEN			19
#define ELEC_THIL			20
#define H_KAR				21
#define HUN_ETT				22
#define MASQ_IL_YR			23
#define MLIN_THOBBYN		24
#define OBLODRA				25
#define S_SRIL				26
#define SYR_THAERL			27
#define TEKEN_DUIS			28
#define THAEYALLA			29
#define X_LARRAZ_ET_SOJ		30
#define FIRST_FALLEN_HOUSE	BRONT_TEJ
#define LAST_FALLEN_HOUSE	X_LARRAZ_ET_SOJ

#define LOLTH_SYMBOL		31

	xchar halu_ward; /* If you draw while halucinating, you inscribe a halucinatory symbol */

/*One type of ward per square
Max of seven redundant copies (so you can fight on the ward)
Note: max of 3 Gorgoneia on a square
Note: max of 4 circles of acheron per square. Makes it a good emergency ward but a poor combat ward.
Note: max of 6 hamsa on the square. Hamsa after the first two must be drawn in pairs
Note: max of 6 elder signs per square. They form a more detailed, star shaped sign.
Note: elder sign becomes more potent at 6 copies.
Note: elder elemental eye becomes more potent at 5 and 7 copies.
Note: Gorgoneia become more potent with each copy.
Note: cartouche of the cat lord becomes more potent at 7 and 9 glyphs.
*/
	xchar complete_wards; // functional
	xchar scuffed_wards; // 90%
	xchar degraded_wards;// 75%
	xchar partial_wards;// 50%
};

#define newengr(lth) (struct engr *)alloc((unsigned)(lth) + sizeof(struct engr))
#define dealloc_engr(engr) free((genericptr_t) (engr))

#endif /* ENGRAVE_H */
