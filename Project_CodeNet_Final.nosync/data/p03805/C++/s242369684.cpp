#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <iomanip>
#include <stack>
#include <fstream>
#include <cstdint>
#include <cmath>
#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>
using namespace std;
typedef int64_t ll;
typedef uint64_t ull;
constexpr uint64_t L1 = 1ull;
constexpr ull bit(int n){ return 1ull << n;}

constexpr ll INF       = 1000000000;/* 1e+9a */
// for(auto && i : Range(l,r))
// -> i = [l..r)
class Range {
private: struct It{ int x; int operator*(){return x;}
 bool operator!=(It& lhs){ return x<lhs.x;} void operator++(){++x;} }; It l,r;
public: Range(int n):l({0}),r({n}){} Range(int i,int n):l({i}),r({n})
 {}It& begin(){return l;} It& end(){return r;} };

void solve(istream& cin) {
    int N, M;
    while(cin >> N >> M){
        vector<set<int>> v(N, set<int>());
        for (int i = 0; i < M; ++i) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            v[a].insert(b);
            v[b].insert(a);
        }
        ll count = 0;
        vector<int> rt(N);
        for (int i = 0; i < rt.size(); ++i) { rt[i] = i; }
        do{
            count += [&v, &rt]() {
                for (int i = 1; i < rt.size(); ++i) {
                    if (v[rt[i-1]].count(rt[i]) == 0)
                        return 0;
                }
                return 1;
            }();
        } while(next_permutation(rt.begin()+1, rt.end()));
        cout << count << endl;
    }
}

int main(int argc, char *argv[]) {
    string FileName("C"), Modifier("MEPH_");
    string ExecutionName = Modifier + FileName;
    string sub(argv[0]);
    if(sub.size() > ExecutionName.size())
        sub = sub.substr(sub.size()-ExecutionName.size(), ExecutionName.size());

    cout << setprecision(16) << scientific;
    if (sub != ExecutionName) {
        cin.tie(0);
        ios::sync_with_stdio(false);
        solve(cin);
    }
    else {    
	    cerr << sub << endl;
        string inFile = "sample.txt";
        auto fs = fstream(inFile, fstream::in);
        solve(fs);
    }
}