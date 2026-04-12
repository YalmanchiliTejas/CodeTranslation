#include<bits/stdc++.h>

using namespace std;

#define FOR(i,n)	for(int i=0;i<(int)n;i++)
#define FOB(i,n)	for(int i=n;i>=1;i--)
#define MP(x,y)	make_pair((x),(y))
#define ii pair<int, int>
#define lli long long int
#define ulli unsigned long long int
#define lili pair<lli, lli>
#ifdef EBUG
#define DBG	if(1)
#else
#define DBG	if(0)
#endif
#define SIZE(x) int(x.size())
const int infinity = 2000000999 / 2;
const long long int inff = 4000000000000000999;

typedef complex<long double> point;

template<class T>
T get() {
    T a;
    cin >> a;
    return a;
}

template <class T, class U>
ostream& operator<<(ostream& out, const pair<T, U> &par) {
    out << "[" << par.first << ";" << par.second << "]";
    return out;
}

template <class T>
ostream& operator<<(ostream& out, const set<T> &cont){
    out << "{";
    for (const auto &x:cont) out << x << ", ";
    out << "}";
    return out;
}

template <class T, class U>
ostream& operator<<(ostream& out, const map<T,U> &cont){
    out << "{";
    for (const auto &x:cont) out << x << ", ";
    out << "}"; return out;
}

template <class T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  FOR(i, v.size()){
    if(i) out << " ";
    out << v[i];
  }
  out << endl;
  return out;
}

bool ccw(point p, point a, point b){
  if((conj(a - p) * (b - p)).imag() <= 0) return(0);
  else return(1);
}

int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    
    int a = get<int>();
    int b = get<int>();
    
    vector<vector<int> > D(a, vector<int>(b));
    int mx = 0;
    FOR(i, a){
        FOR(j, b) D[i][j] = get<int>();
        FOR(j, b) mx = max(mx, D[i][j]);
    }
    
    vector<vector<int> > minc(mx + 1, vector<int>(mx + 1, 0));
    
    FOR(i, mx + 1){
        FOR(j, mx + 1){
            FOR(l, a){
                FOR(y, b){
                    DBG cout << "Pri : " << i << " * " << l + 1 << " + " << j << " * " << y + 1 << " + c = " << D[l][y];
                    minc[i][j] = max(minc[i][j], D[l][y] - (l + 1) * i - (y + 1) * j);
                    DBG cout << " => minc: " << minc[i][j] << endl;
                }
            }
        }
    }
    
    DBG cout << " " << minc;
    
    vector<vector<ii> > ktore(a, vector<ii>(b, make_pair(-1, -1)));
    set<ii> used;
    
    FOR(i, mx + 1){
        FOR(j, mx + 1){
            FOR(l, a){
                FOR(y, b){
                    if(minc[i][j] == D[l][y] - (l + 1) * i - (y + 1) * j){
                        if(ktore[l][y].first == -1 || ktore[l][y].second + ktore[l][y].first > j + i){
                            ktore[l][y] = {i, j};
                        }
                    }
                }
            }
        }
    }
    
    FOR(i, a){
        FOR(j, b){
            if(ktore[i][j].first < 0){
                DBG cout << "Neda sa pripradit :( " << i << " a " << j << endl;
                cout << "Impossible" << endl;
                return 0;
            }
            DBG cout << "Plati, ze " << ktore[i][j] << " x " << i + 1 << " | " << j + 1 << " bude rovne " << endl;
            used.insert(ktore[i][j]);
        }
    }
    
//     cout << "Possible" << endl;
    int maxi = (--used.end())->first;
    int n = maxi + 1;
    vector<pair<ii, int> > hrany;
    FOR(i, maxi){
        hrany.push_back({{i, i + 1}, -1});
    }
    vector<int> mxs(maxi + 1, 0);
    vector<vector<int> > M(maxi + 1);
    for(ii a : used){
        mxs[a.first] = max(mxs[a.first], a.second);
        M[a.first].push_back(a.second);
    }
    
    int yps = 0;
    
    FOR(i, maxi + 1){
        yps += mxs[i];
        DBG cout << "yps += " << mxs[i] << endl;
    }
    
    n += yps;
    
    n ++;
    
    if(n <= 300) cout << "Possible" << endl;
    else{
        cout << "Impossible" << endl;
        return 0;
    }
    
    int v = maxi + 1;
    
    FOR(i, maxi + 1){
        int f = v;
        int last = i;
        FOR(j, mxs[i]){
            hrany.push_back({{last, v}, -2});
            last = v;
            v ++;
        }
        
        for(int a : M[i]){
            if(!a){
                hrany.push_back({{i, n - 1}, minc[i][a]});
            }
            else{
                if(f + a - 1 != n - 1) hrany.push_back({{f + a - 1, n - 1}, minc[i][a]});
            }
        }
        
    }
    
    cout << n << " " << hrany.size() << endl;
    for(auto e : hrany){
        cout << e.first.first + 1 << " " << e.first.second + 1 << " ";
        if(e.second < 0) cout << (e.second == -1 ? "X" : "Y") << endl;
        else cout << e.second << endl;
    }
    
    cout << 1 << " " << n << endl;
    
}
