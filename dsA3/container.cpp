/*
FILE		: container.cpp
PROJECT		: dsA3	
BY			: SAMEER SAPRA
DATE		: 31-03-2014
DESCRIPTION	: This file has a function which stores the title and artist information in container( map ).  
*/

/*Test Branch*/
#include"prototypes.h"

/*
FUNCTION NAME : map<string , string> store_in_multi( char directory[] , map< string , string > title_artist_info , int *number_of_songs )

PARAMETERS	  : char directory[]							: Stores the command argument
				map< string , string > title_artist_info	: Associate container(map).
				int *number_of_songs						: Counts the total number of songs.

DESCRIPTION	  : This function extracts the artist and title information from the song and stroes in the map container.

RETURN		  : It returns the container(map).

*/

/*map<string , string> */ void store_in_multi( char directory[] , map< string , string > title_artist_info , int *number_of_songs )
{

	//Initializing local variables. 
	char *token		= NULL ;
	
	string token1	= "" ;
	string token2	= "" ;

	int token_number = 0 ;

	WIN32_FIND_DATA		file_data = { 0 } ;
	HANDLE				e		  = FindFirstFile( directory , &file_data ) ;

	//Checking if directory exists or not.
	if( e != INVALID_HANDLE_VALUE )
	{
		do
		{
			//Taking the first string from the song separated by '-'.
			token = strtok( file_data.cFileName , "-\n" ) ;
			while( token != NULL )
			{
				//Getting only the first string.
				if( token_number == kZERO )
				{
					token1 = token ;
				}

				//Getting only the second string between '-' and '.' 
				if( token_number == kONE )
				{
					token2 = token ;

					//Adds title as a key and artist into the container. 
					title_artist_info.insert( make_pair ( token2, token1 ) ) ;
				}
				token = strtok ( NULL , "-\n" ) ;
				token_number++ ;
			}
			token_number = 0 ;
			(*number_of_songs)++ ;

		}while( FindNextFile( e , &file_data ) ) ;
	}
	//return title_artist_info ;
}
