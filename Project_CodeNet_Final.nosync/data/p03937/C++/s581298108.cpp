#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 100000
#define MOD 1000000007
#define INF 1000000000

int main()
{
        int n, m;
        cin >> n >> m;
        string a[8];
        for(int i = 0; i < n; i++){
                cin >> a[i];
        }

        queue<pii> q;
        q.push(mp(0, 0));
        map<pii, int> used;
        while(!q.empty()){
                pii cur = q.front();
                q.pop();
                pii turn1 = cur;
                turn1.first++;
                used[cur] = 1;
                pii turn2 = cur;
                turn2.second++;



                pii turn3 = cur;
                turn3.first--;
                pii turn4 = cur;
                turn4.second--;

                if(turn3.first >= 0 && a[turn3.first][turn3.second] == '#' && !used[turn3] || turn4.second >= 0 && a[turn4.first][turn4.second] == '#' && !used[turn4]){
                        cout << "Impossible";
                        return 0;
                }

                if(cur.first == n - 1 && cur.second == m - 1){
                        break;
                }

                if(!(turn1.first < n && a[turn1.first][turn1.second] == '#' && turn2.second < m && a[turn2.first][turn2.second] == '#')){
                        if(turn1.first < n && a[turn1.first][turn1.second] == '#'){
                                q.push(turn1);
                                used[turn1] = true;
                        }
                        else if(turn2.second < m && a[turn2.first][turn2.second] == '#'){
                                q.push(turn2);
                                used[turn2] = true;
                        }
                        else{
                                cout << "Impossible";
                                return 0;
                        }
                }
                else{
                        cout << "Impossible";
                        return 0;
                }
        }

        cout << "Possible";
        return 0;
}
