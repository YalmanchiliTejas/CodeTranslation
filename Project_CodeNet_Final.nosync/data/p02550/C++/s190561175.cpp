/*
 * Author: Utkal Sinha
 * Created on: 2020-09-19, Sat, 17:48
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

void love() {
    ll n, x, m;
    cin >> n >> x >> m;
    ll ans = 0;
    if(x == 1) ans = n;
    if(x > 1) {
        unordered_map<ll, ll> mp;
        vector<ll> nums;
        nums.push_back(0);

        bool chk = true;
        ll ct = 1;
        while(ct <= n && chk) {
            if(mp.find(x) == mp.end()) {
                ans = ans + x;
                mp[x] = ct;
                nums.push_back(x);
            }
            else {
                ll ls = mp[x];
                ll prd = ct - ls;
                ll sm = 0;
                for(int i = ls; i<nums.size(); i++) {
                    sm = sm + nums[i];
                }

                ll rem = n - ct + 1;
                ll dv = rem / prd;
                ll extra = rem % prd;

                ans += dv * sm;
                for(int i = 0; i < extra; i++) {
                    ans += nums[ls + i];
                }
                break;
            }
            ct++;
            x = (x*x) % m;
        }
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