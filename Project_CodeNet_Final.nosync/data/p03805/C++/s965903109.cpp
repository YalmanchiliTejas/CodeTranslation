#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <utility>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#define MOD 1000000007
#define int long long
using namespace std;
using P = pair<int, int>;
using ll = long long;
using prique = priority_queue<int>;
signed main(){
    int n,m;
    cin>>n>>m;
    bool pass[8][8]={};
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        pass[a-1][b-1]=true;
        pass[b-1][a-1]=true;
    }
    vector<int> p;
    for(int i=1;i<=n;i++)p.push_back(i);
    int ans=0;
    do{
        bool po=true;
        for(int i=0;i<n-1;i++){
            if(pass[p[i]-1][p[i+1]-1]==false){
                po=false;
                break;
            }
        }
        if(po)ans++;
    }while(next_permutation(p.begin()+1, p.end()));
    cout<<ans<<endl;
    return 0;
}

