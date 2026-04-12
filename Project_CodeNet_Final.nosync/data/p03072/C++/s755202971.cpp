#include<cstdio>

using namespace std;

int n;

int main(){
    scanf( "%d\n", &n );
    int index = 0, ret = 0;
    for( int i = 0; i < n; i++ ){
        int a; scanf( "%d", &a );
        if( a >= index ){
            ret++;
            index = a;
        }
    }
    printf( "%d\n", ret );
    return 0;
}