#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
#define MAX 100005
#define NIL -1
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

const double PI=(acos(-1));

ll all(ll n){
    return 4*pow(2,n)-3;
}

ll pa(ll n){
    return all(n)/2+1;
}

ll f(ll n,ll x){
    if(n==1){
        if(x==1)return 0;
        else if(x==2)return 1;
        else if(x==3)return 2;
        else if(x==4)return 3;
        else if(x==5)return 3;
        else return 0;
    }else{
        if(x==1)return 0;
        else if(x>1&&x<=all(n-1)+1)return f(n-1,x-1);
        else if(x==2+all(n-1))return pa(n-1)+1; 
        else if(x>2+all(n-1)&&x<=2+2*all(n-1))return pa(n-1)+1+f(n-1,x-2-all(n-1));
        else if(x==3+2*all(n-1))return 2*pa(n-1)+1; 
        else return 0;
    }
}

int main(){
    ll n,x;
    cin>>n>>x;
    cout<<f(n,x)<<endl;
}