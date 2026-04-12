#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

template<ll mod>
struct NT{
    static int add(int const&a, int const&b){
        ll ret = a+b;
        if(ret>=mod) ret-=mod;
        return ret;
    }
    static int& xadd(int& a, int const&b){
        a+=b;
        if(a>=mod) a-=mod;
        return a;
    }
    static int sub(int const&a, int const&b){
        return add(a, mod-b);
    }
    static int& xsub(int& a, int const&b){
        return xadd(a, mod-b);
    }
    static int mul(int const&a, int const&b){
        return a*(ll)b%mod;
    }
    static int& xmul(int &a, int const&b){
        return a=mul(a, b);
    }
    static int inv_rec(int const&a, int const&m){
        assert(a!=0);
        if(a==1) return 1;
        int ret = m+(1-inv_rec(m%a, a)*(ll)m)/a;
        return ret;
    }
	// this is soooo great, can even be used for a sieve
    static int inv_rec_2(int const&a, int const&m){
        assert(a!=0);
        if(a==1) return 1;
        int ret = m-NT<mod>::mul((m/a), inv_rec_2(m%a, m));
        return ret;
    }
    static int inv(int const&a){
        return inv_rec_2(a, mod);
    }
};
constexpr int mod = 1e9+7;
using nt = NT<mod>;
const int tt = nt::inv(2);

int ipow(int a, int exp){
    int ret = 1;
    for(;exp;exp>>=1){
        if(exp&1){
            nt::xmul(ret, a);
        }
        nt::xmul(a, a);
    }
    return ret;
}

struct Inter{
    int l, r;
    int dp, alt;
    bool operator<(Inter const&o)const{
        return make_pair(l, r) < make_pair(o.l, o.r);
    }
};

signed main()
{
    #ifdef LOCAL_RUN
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int TTT; cin >> TTT; while(TTT--){
    #else
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    #endif // LOCAL_RUN

    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &e:a){
        cin >> e;
    }
    vector<Inter> inters;

    int old_h = 1e9;
    auto down = [&](int h){
        assert(old_h >= h);
        if(old_h > h){
            int dh = old_h - h;
            int fact = ipow(2, dh);
            for(auto &e:inters){
                nt::xmul(e.alt, fact);
            }
        }
        old_h = h;
    };

    for(int it=0;it<n;++it){
        int j = max_element(a.begin(), a.end()) - a.begin();
        int h = a[j];
        down(h);
        a[j] = -1;
        inters.emplace_back(Inter{j, j, 0, 2});

        for(int _:{0, 1}){ (void)_;
            sort(inters.begin(), inters.end());
            for(int i=1;i<(int)inters.size();++i){
                if(inters[i-1].r+1 == inters[i].l){
                    //merge
                    Inter const a = inters[i-1], b = inters[i];
                    Inter res{a.l, b.r, 0, 0};

                    nt::xadd(res.dp, nt::mul(a.dp, b.dp));
                    nt::xadd(res.dp, nt::mul(a.dp, b.alt));
                    nt::xadd(res.dp, nt::mul(a.alt, b.dp));
                    nt::xadd(res.dp, nt::mul(nt::mul(a.alt, b.alt), tt));
                    nt::xadd(res.alt, nt::mul(nt::mul(a.alt, b.alt), tt));

                    inters[i-1] = res;
                    inters.erase(inters.begin()+i);
                    --i;
                }
            }
        }
    }
    down(1);

    assert(inters.size() == 1);
    int ans = nt::add(inters[0].dp, inters[0].alt);
    cout << ans << "\n";




    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}
