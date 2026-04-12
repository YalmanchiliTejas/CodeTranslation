#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N) cin >> A[i];
    
    multiset<int> s;
    REP(i, N){
        auto itr = s.lower_bound(A[i]);
        // cout << *itr << " " << boolalpha << (itr == s.begin()) << endl;
        if(itr != s.begin()) s.erase(--itr);
        s.insert(A[i]);
    }
    cout << s.size() << endl;
    
    return 0;
}