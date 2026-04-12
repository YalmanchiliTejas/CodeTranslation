#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>
#define mop 1000000007

using namespace std;

static const int MAX = 9;
int G[MAX][MAX] = {};
int main() {
    
    int n,m;
    cin >> n >> m;
    for (int i = 0;i<m;i++){
        int a,b;
        cin >> a >> b;
        G[a][b] = 1;
        G[b][a] = 1;
    }
    vector <int> v;
    for (int i=1;i<=n;i++){
        v.push_back(i);
    }
    long long ans = 0;
    do{
        for (int i=1;i<n;i++){
            if(i==1 and v[0] != 1){
                goto Next;
            }
            if(G[v[i]][v[i-1]] != 1){
                goto Next;
            }
        }
        ans += 1;
        
        Next:
        ;
    }while(next_permutation(v.begin(),v.end()));
    cout << ans << endl;
}