/*
 * Author: Utkal Sinha
 * Created on: 2020-08-29, Sat, 18:0
 * Problem:
 * Platfrom: General
 * */
#if USE_BOOST2
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_bin_float.hpp>
namespace bst = boost::multiprecision;
typedef bst::int1024_t vll; //int512_t or //int128_t
typedef bst::cpp_bin_float_100 vdouble;
#endif

#include <bits/stdc++.h>
using namespace std;
#define GETTIME std::chrono::system_clock::now()
#define DURATION std::chrono::duration<double>
#ifdef MY_DEV_ENV2
#define LOCALDEV
#endif
typedef long long ll;
typedef std::chrono::system_clock::time_point TPT;
static TPT starttime, endtime, timelimit;
static double problem_tle = 1.5;
static inline void calc_problem_end_time() {timelimit = starttime + std::chrono::milliseconds(int (problem_tle * 1000));}
// template end

ll MD = 1000000007;

void love() {
    ll n;
    cin >> n;
    ll arr[n];
    for(int i= 0; i<n; i++) cin >> arr[i];

    ll ps[n+1];
    ps[0];
    for(int i= 1; i<=n; i++) ps[i] = (ps[i-1] + arr[i-1]) % MD;

    ll ans = 0;
    for(int i= 0; i<n-1; i++) {
        ll ts = (ps[n] - ps[i+1] + MD) % MD;
        ts = (arr[i] * ts) % MD;
        ans = (ans + ts) % MD;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    srand(time(0));
#ifdef LOCALDEV
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
#ifdef LOCALDEV
    starttime = GETTIME;
    calc_problem_end_time();
#endif
    while(t--) love();
#ifdef LOCALDEV
    endtime = GETTIME;
    DURATION elapsed_seconds = endtime - starttime;
    DURATION time_limit_seconds = timelimit - starttime;
    clog << "Elapsed time: " << elapsed_seconds.count() << "s\n";
    clog << "Time limit: " << time_limit_seconds.count() << "s\n";
#endif
    return 0;
}