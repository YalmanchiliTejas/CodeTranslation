#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <tuple>
#include <functional>
#include <cstring>

#define PI 3.14159265359
#define INF 1e9
#define LINF 1e18
#define IMOD 1000000007 
#define irep(i,n) for(int  i = 0; i < n; i++)
#define irep2(i,a,n) for(int i = a; i < n; i++)
#define lrep(i,n) for(long long  i = 0; i < n; i++)
#define lrep2(i,a,n) for(long long i = a; i < n; i++)

typedef long long ll;
typedef std::vector<int> v_int;
typedef std::vector<std::vector<int> > v2_int;
typedef std::vector<ll> v_ll;
typedef std::vector<std::vector<ll> > v2_ll;
typedef std::vector<std::string> v_string;
typedef std::vector<std::vector<std::string> > v2_string;
typedef std::pair<ll, ll> pll;

using namespace std;

struct compare {
    bool operator()(const std::string& first, const std::string& second) {
        return first.size() < second.size();
    }
};


int main() 
{
    int n; 
    cin >> n;
    v_int ans(26, 51);
    string alpha = "abcdefghijklmnopqrstuvwxyz";

    irep(i, n) {
        string tmp;
        cin >> tmp;
        v_int abc(26, 0);
        irep(j, tmp.size()) {
            abc[tmp[j] - 'a']++;
        }

        irep(j, 26) {
            ans[j] = min(ans[j], abc[j]);    
        }
    }

    irep(i, 26) {
        irep(j, ans[i]) {
            cout << alpha[i];
        }
    }
    
    return 0;
}
