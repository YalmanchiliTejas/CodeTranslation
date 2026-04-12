#include <bits/stdc++.h>

using namespace std;
#define _for(i,j,N) for(int i = (j);i < (N);i++)
#define _rep(i,j,N) for(int i = (j);i <= (N);i++)
#define _dec(i,j,N) for(int i = (N-1);i >= (j);i--)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define LL long long

template<typename T>
ostream& operator<<(ostream& os,const vector<T>& v) {
    _for(i,0,v.size()) os << v[i] << " ";
    return os;
}

template<typename T>
ostream& operator<<(ostream& os,const set<T>& v){
    for(typename set<T>::iterator it = v.begin();it != v.end();it++)
    os << *it <<" ";
    return os;
}

LL B[51];
LL P[51];

void init(){
    B[0] = 1;
    P[0] = 1;

    _for(i,1,51){
        B[i] = 2*B[i-1] + 3;
        P[i] = 2*P[i-1] + 1;
    }
}

LL N,X;

LL searching(int n,LL x){
    LL ret_val = 0;
    LL b = B[n];
    if(x >= b) return P[n];
    x--;
    LL b2 = B[n-1];

    if(x){
        if(x >= b2){
            x -= b2;
            ret_val += searching(n-1,b2);
        }
        else{
            ret_val += searching(n-1,x);
            x = 0;
        }
    }

    if(x){x--;ret_val++;}
    if(x){
        ret_val += searching(n-1,x);
    }
    return ret_val;
}

int main()
{
    init();
    cin >> N >> X;

    cout << searching(N,X) <<endl;

    return 0;
}