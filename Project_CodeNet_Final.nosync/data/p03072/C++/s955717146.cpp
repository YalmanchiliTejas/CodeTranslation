#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////
int N;
int i, j,ans;
int main(){
    scanf("%d", &N);

    fornum(i,0,N){
        int h;
        scanf("%d", &h);
        if(j<=h){
            j=h;
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}