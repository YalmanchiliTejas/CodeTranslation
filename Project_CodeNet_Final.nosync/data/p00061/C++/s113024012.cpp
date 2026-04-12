#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp( pair< int, int > a, pair< int, int > b )
{
    return a.second > b.second ;
}

int main()
{
    vector< pair< int,int> > p( 30 );
    int key = 0, value = 0, cnt = 0;
    while( scanf( "%d,%d\n", &key, &value ) != EOF )
    {
        cnt++;
        if( key == 0 && value == 0 )break;
        p[cnt].first = key;
        p[cnt].second = value;    
    }
    sort( begin(p), end(p), cmp );
    /* for( int i = 0;i < 30; i++ )
    {
        key = p[i].first;
        value = p[i].second;
        printf( "key:%d ,value:%d\n", key, value );

    } */
    vector< pair< int, int > > rank(30);
    int pos = 0;
    rank[0].second = 1;
    while( pos < 30 )
    {
        rank[pos].first = p[pos].first;
        if( p[pos].second == p[pos + 1].second )
        {
            rank[pos + 1].second = rank[pos].second;
        }
        else
        {
            rank[pos + 1].second = rank[pos].second + 1;
        }
        
        pos++;
    }
    int num = 0;
    while( scanf( "%d\n", &num ) != EOF )
    {
        for( int i = 0; i < 30; i++ )
        {
            if( rank[i].first == num )
            {
                printf( "%d\n", rank[i].second );
                break;
            }
        }
    }
    return 0;
}
