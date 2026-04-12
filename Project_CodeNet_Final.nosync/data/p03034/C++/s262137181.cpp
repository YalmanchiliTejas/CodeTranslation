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
const int maxn = 1e5+5;
LL S[maxn];

int main()
{
    int N;
    scanf("%d",&N);
    _for(i,0,N){
        cin >> S[i];
    }

    LL ans = S[N-1];

    _for(C,1,N){
        LL num = S[N-1];
        _for(k,1,N){
            int A = N-1-k*C;
            if(C >= A || (!(A%C) && A/C <= k)) break;
            //cout << "C:" << C <<" "<<"A:"<<A<<endl;
            num += S[k*C];
            num += S[A];
            ans = max(ans,num);
            //cout << "num: "<<num <<endl;
        }
    }
    cout << ans << endl;
    return 0;
}
