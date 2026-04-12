#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mem[9][1<<9];
int n , m ;
vector<int>v[9];

int dp(int i,int x){
if( x+1 == 1<<n )return 1;
int &ret = mem[i][x];
if( ret != -1 )return ret;
ret=0;

for(auto j:v[i])
    if( !(x&( 1<<j )) )
        ret+=dp(j,x+(1<<j));
return ret;
}

int main(){
memset(mem,-1,sizeof mem);
cin>>n>>m;
while( m-- ){
    int x , y ;cin>>x>>y;
    x--;y--;
    v[x].push_back(y);
    v[y].push_back(x);
}
cout<<dp(0,1)<<endl;
return 0;
}
