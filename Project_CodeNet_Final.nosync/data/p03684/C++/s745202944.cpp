#include "bits/stdc++.h"
using namespace std;
const long long N = 1e5 + 5;
long long n;
bool marked[N];
pair < long long , long long > b[N];
pair < long long , long long > c[N];
map < long long , set < pair < long long , long long > > > a;
long long prim(long long x){
            priority_queue < pair < long long , long long > , vector < pair < long long , long long > > , greater < pair < long long , long long > > > Q;
            long long y;
            long long mini = 0;
            pair < long long , long long > p;
            Q.push(make_pair(0 , x));
            while(!Q.empty()){
                    p = Q.top();
                    Q.pop();
                    x = p.second;
                    if(marked[x] == true){
                            continue;
                    }
                    mini += p.first;
                    marked[x] = true;
                    for(auto j : a[x]){
                            y = j.second;
                            if(marked[y] == false){
                                    Q.push(j);
                            }
                    }
            }
            return mini;
}
int main()
{
            ios_base::sync_with_stdio(false);
            cin.tie(0);
            cout.tie(0);
            cin >> n;
            for(long long i = 0 ; i < n ; i++){
                    cin >> b[i].first >> b[i].second;
                    c[i].first = b[i].second;
                    c[i].second = i;
                    b[i].second = i;
            }
            sort(b , b + n);
            sort(c , c + n);
            for(long long i = 0 ; i < n - 1 ; i++){
                    long long x = b[i].second;
                    long long y = b[i + 1].second;
                    a[x].insert(make_pair(b[i + 1].first - b[i].first , y));
                    a[y].insert(make_pair(b[i + 1].first - b[i].first , x));
            }
            for(long long i = 0 ; i < n - 1 ; i++){
                    long long x = c[i].second;
                    long long y = c[i + 1].second;
                    a[x].insert(make_pair(c[i + 1].first - c[i].first , y));
                    a[y].insert(make_pair(c[i + 1].first - c[i].first , x));
            }
            long long mini = prim(1);
            cout << mini << endl;
            return 0;
}
