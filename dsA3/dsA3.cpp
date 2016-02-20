/*
FILE		: dsA3.cpp
PROJECT		: dsA3	
BY			: SAMEER SAPRA
DATE		: 31-03-2014
DESCRIPTION	: This program takes name of the directory as a command argument and finds its .mp3 file and get the title and artist name from it.
			  The names are stoed in associative container i.e map sorted by song as a key.The command argument can be entered in 2 forms either
			  \ at the end of the argument or not.
*/


#include"prototypes.h" 

int main( int argc , char *argv[] )
{
	//Initializing local variables.

	int loop1		= 0 ;
	int length		= 0 ;
	int check		= 0 ;
	int count_songs = 0 ;
	int counter		= 1 ;

	
	//Associate container.
	map<string , string> copy_of_title_artist_info ;

	//For each command argument entered by the user.
	for( loop1 = kONE ; loop1 < argc ; loop1++ )
	{
		char directory[100] = "" ;
		char temp_dir[100] = "" ;

		//Getting the length of the first command argument.
		length = strlen( argv[loop1] ) ;
		strcpy( temp_dir , argv[loop1] ) ;

		//Checking if last character is \\ or not.
		if( ( temp_dir[length - kONE ] == kBACKSLASH ) )
		{
			//Copy the string before the last \\ in the command argument.
			strncpy( directory , temp_dir , length - 1 ) ;
		}

		//If there is no \\ in command argument.
		else
		{
			strcpy( directory , argv[loop1] ) ;
		}
		
		WIN32_FIND_DATA		filedata = { 0 } ;
		HANDLE				h		 = FindFirstFile( directory , &filedata ) ;

		//Checking if directory exists or not. 
		if( h != INVALID_HANDLE_VALUE )
		{
			strcpy( directory , directory ) ;	
			strcat( directory , "\\*.mp3" ) ;
			
			//Calling the function to store the title and artist into STL(map).
			/*copy_of_title_artist_info =  */store_in_multi( directory , copy_of_title_artist_info , &count_songs ) ;
		}
		else
		{
			//Prints one 1 time if more than one command argument is wrong.
			if( check == 0) 
			{
				cout << "Error: Usage: dsAssignment1 <directory ...> for -> " << argv[loop1] << endl << endl ;
				check++;
			}
		}
	}
	
	//Traversing the STL using the iterartor.
	for( map<string ,string>::iterator i = copy_of_title_artist_info.begin() ; i != copy_of_title_artist_info.end() ; i++ ) 
	{
		cout << "TITLE IS :  " << i->first << "\t ARTIST IS : " << i->second << endl;
	
		//User is asked to enter any key after every 20 songs but not if total songs are multiple of 20.
		if( ( ( counter % kTWENTY ) == kZERO ) && ( counter < count_songs ) )
		{
			printf("Pres any key to continue\n") ;
			getch() ;									//Enter any key from the keyboard.
			printf("\n") ;
		}
		counter++;
	}

	return 0 ;
}