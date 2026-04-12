
 //edit  fork	 download
 #include <iostream>
using namespace std;
typedef long long ll;
ll len[51]={1};
ll p[51]={1};
ll sol(ll N, ll X){
    if(X==0){return 0;}
    if(N==0) return X?1:0;
    ll ret=0;
    if(X<=len[N-1]+1){
        ret+=sol(N-1,X-1);
    }
    else{
        ret+=p[N-1];
        X-=len[N-1]+1;
        if(X>0) X--,ret++;
        ret+=sol(N-1,X);
    }
    return ret;
}
int main() {
	ll N,X;
    cin>>N>>X;
    for(int i=1;i<=50;i++){
        p[i]=p[i-1]*2+1;
        len[i]=len[i-1]*2+3;
    }
    cout<<sol(N,X);
	return 0;}