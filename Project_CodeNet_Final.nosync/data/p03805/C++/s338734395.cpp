#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>

int main() {
    int N, M;
    cin>>N>>M;
    vvi G(N);
    REP(i, 0, M){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int count = 0;
    queue<vvi> que;
    que.push({{0}, {0}});
    while(!que.empty()){
       auto cur = que.front(); que.pop();
       int v = cur[0][0];
       vi curArray = cur[1];
       if(curArray.size() == N){
           count++;
//           REP(i, 0, curArray.size()) cout << curArray[i] << " ";
//           cout << endl;
           continue;
       }
       for(int x: G[v]){
           auto itr = find(curArray.begin(), curArray.end(), x);
            if(distance(curArray.begin(), itr) == curArray.size()){
                vi newArray = curArray;
                newArray.push_back(x);
                que.push({{x}, newArray});
            }
        }
    }
    cout << count << endl;
}