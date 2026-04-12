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

//コンビネーションをmodで割った余りを産出
int64_t nCk( int64_t n, int64_t k  )
{
    int64_t ans_x = 1;
    int64_t ans_y = 1;

    for( int i = n; i > n - k; i-- )
    {
        ans_x *= i;
    }

    for( int i = 1; i <= k; i++ )
    {
        ans_y *= i;
    }

    return ans_x / ans_y;
}

int main()
{
    std::string word = "aa";
    std::string w = "Yes";
    int64_t a,b,c,d,e,f;
    std::cin>> a;
    std::cin>> b;
    
    if( a != b )
    {
        w = "No";
    }

    std::cout<< w;
}
