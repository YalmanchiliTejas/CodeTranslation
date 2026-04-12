#include <algorithm>
#include <bitset>
#include <cctype>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
template<class T> inline T sqr(T x) {return x*x;}

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;

#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define each(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define exist(s,e) ((s).find(e)!=(s).end())
#define range(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  range(i,0,n)
#define clr(a,b) memset((a), (b) ,sizeof(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

const double eps = 1e-10;
const double pi  = acos(-1.0);
const ll INF =1LL << 62;
const int inf =1 << 29;

int main(void){
    for(int n, m; cin >> n >> m, n;){
        set< stack<string> > s;
        set< stack<string> > dirs;

        rep(i, n){
            string path; cin >> path;
            replace(all(path), '/', ' ');
            stringstream ss(path);

            stack<string> stk;
            string str;
            while(ss >> str) stk.push(str);

            stack<string> tmp = stk;
            while(!tmp.empty()){
                tmp.pop();
                dirs.insert(tmp);
            }
            s.insert(stk);
        }

        vector<vs> in(m, vs(2));
        rep(i, m) rep(j, 2) cin >> in[i][j];

        rep(i, m){
            string res = "yes";

            vector< stack<string> > stks(2);
            rep(j, 2){
                string path = in[i][j];
                bool isDir = (path[path.size() - 1] == '/');
                replace(all(path), '/', ' ');
                stringstream ss(path);

                stack<string> stk;
                string str;
                bool ok = true;
                while(ss >> str){
                    if(str == ".") continue;
                    else if(str == ".."){
                        if(dirs.find(stk) == dirs.end()){
                            ok = false;
                            break;
                        }

                        if(stk.empty()){
                            ok = false;
                            break;
                        }
                        stk.pop();
                    }
                    else stk.push(str);

                }
                if(!ok){
                    res = "not found";
                    break;
                }

                vector< stack<string> > pathes;
                if(!isDir){
                    pathes.pb(stk);
                }
                stk.push("index.html");
                pathes.pb(stk);

                ok = false;
                rep(k, pathes.size()){
                    if(s.find(pathes[k]) != s.end()){
                        stks[j] = pathes[k];
                        ok = true;
                        break;
                    }
                }
                if(!ok) res = "not found";
            }

            if(res == "yes" && stks[0] != stks[1]){
                res = "no";
            }

            cout << res << endl;
        }
    }

	return 0;
}