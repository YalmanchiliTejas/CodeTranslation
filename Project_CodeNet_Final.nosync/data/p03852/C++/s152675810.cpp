#include<stdio.h>

main()
{
	int c ;

	c = getchar () ;

	if ( c == 97 || c == 105 || c == 117 || c == 101 || c == 111 )
	{
		printf ( "vowel\n" );
		return 0 ;
	}

	printf ( "consonant\n" );

	return 0 ;
}
