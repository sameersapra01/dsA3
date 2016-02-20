/*
FILE		: prototypes.h
PROJECT		: dsA3	
BY			: SAMEER SAPRA
DATE		: 31-03-2014
DESCRIPTION	: This file contains libraries , contants and prototypes used in the program.  
*/

#include<stdio.h>
#include<conio.h>
#include<string>
#include<Windows.h>
#include<iostream>
#include<map>

using namespace std ;

#pragma warning(disable:4996)


//Constants

#define kZERO		0
#define kONE		1
#define kTWENTY		20
#define kBACKSLASH	92
#define kHUNDRED	100


//Prototypes.
/*map<string , string>*/ void store_in_multi( char directory[] , map< string , string > title_artist_info , int *number_of_songs );

