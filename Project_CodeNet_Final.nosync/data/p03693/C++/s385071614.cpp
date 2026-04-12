#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>

using namespace std;

#define int long long
#define REP(i,s,e) for((i)=(s);(i)<(e);(i)++)
#define RREP(i,s,e) for((i)=((s)-1);(i)>=(e);(i)--)

signed main(){
    int R,G,B;

    cin>>R>>G>>B;

    if((R*100+G*10+B)%4==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

