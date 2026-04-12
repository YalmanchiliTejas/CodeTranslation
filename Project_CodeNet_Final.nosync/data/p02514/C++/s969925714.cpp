#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

void searchAccess(const vector<vector<long long> >& graph, bitset<100>& access)
{
    int n = graph.size();
    access.reset();

    access[0] = true;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        for(int i=0; i<n; ++i){
            if(graph[q.front()][i] >= 0 && !access[i]){
                q.push(i);
                access[i] = true;
            }
        }
        q.pop();
    }
}

int main()
{
    for(;;){
        int n, m;
        cin >> n >> m;
        if(n == 0)
            return 0;

        vector<vector<long long> > graph(n, vector<long long>(n, -1));
        vector<long long> cost;
        long long ret = 0;
        for(int i=0; i<m; ++i){
            int a, b;
            long long c;
            cin >> a >> b >> c;
            if(c > 0){
                graph[a][b] = graph[b][a] = c;
                cost.push_back(c);
            }else{
                ret += c;
            }
        }
        m = cost.size();
        sort(cost.begin(), cost.end());

        if(m >= n-1){
            bitset<100> access;
            searchAccess(graph, access);
            if(access.count() == n){
                long long ret2 = INT_MAX;
                if(m == n)
                    ret2 = cost[0] + cost[1];
                for(int i=0; i<n; ++i){
                    for(int j=i+1; j<n; ++j){
                        if(graph[i][j] == -1)
                            continue;
                        long long tmp = graph[i][j];
                        graph[i][j] = graph[j][i] = -1;

                        searchAccess(graph, access);
                        if(access.count() != n)
                            ret2 = min(ret2, tmp);

                        graph[i][j] = graph[j][i] = tmp;
                    }
                }
                ret += ret2;
            }
        }

        cout << ret << endl;
    }
}