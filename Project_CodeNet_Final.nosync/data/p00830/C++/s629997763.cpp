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
const string kYes = "yes";
const string kNo = "no";
const string kNone = "not found";

int main(void){
    for(int n, m; cin >> n >> m, n;){
        set< stack<string> > dirs, files;

        rep(i, n){
            string path; cin >> path;

            replace(all(path), '/', ' ');

            stringstream ss(path);
            stack<string> c_path;
            string str;

            while(ss >> str){
                dirs.insert(c_path);
                c_path.push(str);
            }
            files.insert(c_path);
        }

        rep(i, m){
            string res = kNo;
            set< stack<string> > pathes;

            vs in(2);
            rep(j, 2) cin >> in[j];

            rep(j, 2){
                string path = in[j];

                bool isDir = path.at(path.size() - 1) == '/';
                replace(all(path), '/', ' ');

                stringstream ss(path);
                stack<string> c_path;
                string str;

                while(ss >> str){
                    if(str == ".") continue;
                    if(str == ".."){
                        if(c_path.empty() || dirs.find(c_path) == dirs.end()){
                            res = kNone;
                            break;
                        }
                        c_path.pop();
                    }
                    else c_path.push(str);
                }
                if(res == kNone) break;

                bool ok = false;
                if(!isDir && files.find(c_path) != files.end()){
                   res = pathes.insert(c_path).second ? res:kYes; 
                   ok = true;
                }
                if(!ok){
                    c_path.push("index.html");

                    if(files.find(c_path) != files.end()){
                        res = pathes.insert(c_path).second ? res:kYes;
                        ok = true;
                    }
                }

                if(!ok){
                    res = kNone;
                    break;
                }
            }

            cout << res << endl;
        }
    }

	return 0;
}