#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll F(ll N, ll X){
    if(N==1&&X==1){return 0;}
    else if(N==1&&X==5){return 3;}
    else if(N==1){return X-1;}
    else if(N>1&&X==1){
        return 0;
    }
    else if(N>1&&2<=X&&X<=pow(2,N+1)-2){
        return F(N-1,X-1);
    }
    else if(N>1&&X==pow(2,N+1)-1){
        return pow(2,N);
    }
    else if(N>1&&X>=pow(2,N+1)&&X<=pow(2,N+2)-4){
        return pow(2,N)+F(N-1,X-pow(2,N+1)+1);
    }
    else if(N>1){
        return pow(2,N+1)-1;
    }
}


int main(){
ll N;
cin >> N;
ll X;
cin >> X;
cout<<F(N,X)<<endl;

return 0;


}  

