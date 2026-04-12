#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;
typedef pair<int, double> Pid;
typedef pair<double, int> Pdi;
typedef pair<double, double> Pdd;
typedef pair<ll, ll> P;
typedef pair<P, ll> PP;

const ll mod = 1e9+7;
const int INF = 2e9;
const double epsilon = 1e-7;
const double PI = 3.1415926535;

ll mi(ll x, ll y){
    if(x<y)return x;
    return y;
}
vector <int> v[100000];
int si[100000];

void era(int now){
    si[now] = -1;
    for(int i = 0;i < v[now].size();i++){
        int ne = v[now][i];
        if(si[ne] != -1){
            si[ne] = -1;
            for(int j = 0;j < v[ne].size();j++){
                int nene = v[ne][j];
                if(si[nene] < 1)continue;
                if(si[nene] == 2)era(nene);
                else si[nene]--;
            }
        }
    }
    return;
}
int main(void){
    int n; cin >> n;
    for(int i = 0;i < n - 1;i++){
        int a, b; cin >> a >> b; a--; b--;
        v[a].push_back(b); v[b].push_back(a);
    }
    if(n == 2){cout << "Second" << endl; return 0;}
    if(n == 3){cout << "First" << endl; return 0;}
    /*
    for(int i = 0;i < n;i++){
        if(v[i].size() > 2){
            int count = 0;
            vector <int> vi;
            for(int j = 0;j < v[i].size();j++){
                if(v[v[i][j]].size() == 1)count++;
                if(v[v[i][j]].size() == 2)vi.push_back(v[i][j]);
            }
            if(count > 1){cout << "First" << endl; return 0;}
            if(count == 1 && vi.size() > 0){
                for(int j = 0;j < vi.size();j++){
                    for(int k = 0;k < 2;k++){
                        int he = v[vi[j]][k];
                        if(he == i)continue;
                        for(int l = 0;l < v[he].size();l++){
                            if(v[v[he][l]].size() == 1){
                                cout << "First" << endl; return 0;
                            }
                        }
                    }
                }
            }
        }
    }*/
    /*for(int i = 0;i < n;i++){
        int flag = 1;
        for(int j = 0;j < v[i].size();j++){
            int e = v[i][j];
            int flage = 0;
            for(int k = 0;k < v[e].size();k++){
                if(v[e][k] == i)continue;
                if(v[v[e][k]].size() == 1){flage = 1; break;}
            }
            if(!flage)flag = 0;
        }
        if(flag){cout << "First" << endl; return 0;}
    }*/
    for(int i = 0;i < n;i++)si[i] = v[i].size();
    int flag = 1;
    while(flag){
        flag = 0;
        for(int i = 0;i < n;i++){
            if(si[i] == 0){cout << "First" << endl; return 0;}
            if(si[i] > 0)flag = 1;
            if(si[i] == 1)era(i);
        }
    }
    cout << "Second" << endl;
	return 0;
}
