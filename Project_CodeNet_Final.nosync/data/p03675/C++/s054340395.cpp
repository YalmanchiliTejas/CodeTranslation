
#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define size(n) ( int( n.size() ) )
#define sqr(n) ( (n) * (n) )
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 5;
int a[N];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for ( int i = 1; i <= n; i++ ){
        scanf("%d",&a[i]);
    }
    if ( n % 2 == 0 ){
        for ( int i = n; i > 0; i -= 2 ){
            printf("%d ",a[i]);
        }
        for ( int i = 1; i <= n - 1; i += 2 ){
            printf("%d ",a[i]);
        }
    }
    else{
        for ( int i = n; i >= 1; i -= 2 ){
            printf("%d ",a[i]);
        }
        for ( int i = 2; i <= n - 1; i += 2 ){
            printf("%d ",a[i]);
        }
    }
    return 0;
}
