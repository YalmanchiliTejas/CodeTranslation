#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
#include<cmath>
#include<sstream>
#include<iomanip>
#include <map>
#include <stack>

struct max_min
{
    int64_t max = 0;
    int64_t min = 0;
};

const int64_t cc = pow( 10, 9 ) + 7;
//std::cout<< std::fixed << std::setprecision(10) << ( double )( max ) / 2;
bool sort_pair( std::pair< int64_t, int64_t > origin, std::pair< int64_t, int64_t > another )
{
    return origin.first < another.first;
}


int main()
{
    std::string word = "aa";
    int64_t a,b,c,d,e,f;
 
    std::vector< std::pair< int64_t, int64_t > > list;
    std::cin>> word;

    std::string aa = "No";

if( word.size() != 1 )
    {
        for( int i = 1; i < word.size(); i++ )
        {
            if( word[0] != word[i] )
            {
                aa = "Yes";
            }
        }
    }
    
 std::cout<< aa;
}
