#include <bits/stdc++.h>

using namespace std;
#define _for(i,j,N) for(int i = (j);i < (N);i++)
#define _rep(i,j,N) for(int i = (j);i <= (N);i++)
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

const int maxn = 105;

string G[maxn];
int row[maxn];
int line[maxn];

int main()
{
    int H,W;
    cin >> H >> W;getchar();
    _for(i,0,H){
        getline(cin,G[i]);
    }

    _for(i,0,H){
        _for(j,0,W){
            if(G[i][j] == '#'){
                row[i] = 1;
                line[j] = 1;
            }
        }
    }
    _for(i,0,H){
        if(!row[i])continue;
        _for(j,0,W){
            if(!line[j]) continue;
            printf("%c",G[i][j]);
        }
        printf("\n");
    }

    return 0;
}
