/*	SCCS Id: @(#)zap.h	3.4	1997/05/01	*/
/* Copyright (c) Izchak Miller, 1989.				  */
/* NetHack may be freely redistributed.  See license for details. */

#ifndef ZAP_H
#define ZAP_H

struct zapdata {
	int adtyp;				/* damage type (AD_type) */
	Bitfield(ztyp, 3);		/* originator of zap (ZAP_type) */
#define ZAP_WAND	1
#define ZAP_SPELL	2
#define ZAP_BREATH	3
#define ZAP_RAYGUN	4
	int damn;				/* number of dice */
	int damd;				/* size of dice */
	int flat;				/* alternative to damn and damd -- flat damage to deal */

	Bitfield(unreflectable, 2);	/* zap is harder/impossible to reflect */
#define ZAP_REFL_ADVANCED		0x1
#define ZAP_REFL_NEVER			0x2
#define enhanced_zap(zapdat)	((zapdat)->unreflectable & ZAP_REFL_ADVANCED)
#define noreflect_zap(zapdat)	((zapdat)->unreflectable & ZAP_REFL_NEVER)

	Bitfield(single_target, 1);	/* stops on first target hit */
	Bitfield(explosive, 1);		/* causes a standard explosion at end of range */
	Bitfield(splashing, 1);		/* causes a splash at end of range */
	Bitfield(directly_hits, 1);	/* actually hits monsters. Usually TRUE, but often FALSE if explosive or splashing. */
//	Bitfield(fat_zap, 1);		/* wide zap hits 3-wide. only the center part bounces, though*/
};


#endif /* ZAP_H */
