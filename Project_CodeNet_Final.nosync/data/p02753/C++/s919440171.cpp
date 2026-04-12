#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")

#include<bits/stdc++.h>
using namespace std;

namespace basic{
    using ll =long long int;
    #define imax INT_MAX
    #define lmax LLONG_MAX
    #define pb push_back
    #define ld long double
    #define pii pair<int,int>
    #define pll pair<ll,ll>
    #define v vector
    #define vll vector<ll>
    #define vv(a) vector<vector<a>>
    #define cld complex<ld>
    #define cll complex<ll>
    #define all(x) (x).begin(),(x).end()
    #define rall(x) (x).rbegin(),(x).rend()
    #define mini(a) *min_element(all(a))
    #define maxi(a) *max_element(all(a))
    #define sum_vec(a) accumulate(all(a),0LL)
    #define trans_lower(s) transform(all(s),s.begin(),::tolower)
    #define trans_upper(s) transform(all(s),s.begin(),::toupper)
    #define Pi acos(-1)
    #define f first
    #define se second
    #define lb lower_bound
    #define ub upper_bound
    #define endl "\n"
    #define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
    #define tc int t=0;cin>>t;while(t--)
    #define tc1 int t=1;while(t--)
    #define tc_case int t=0,a_t=0;cin>>t;a_t=t;while(t--)
    #define case(a) cout<<"Case #"<<a_t-t<<" : "<<a<<endl;
    const ll inf = 1e9+7;
    template<class T>void refresh(T &a,ll n){
        assert(n>=0);
        a.clear();a.resize(n);
    }
    template<class X,class Y>void refresh_with_value(X &a,ll n,Y value){
        assert(n>=0);
        a.clear();a.resize(n,value);
    }
    template<class X>void Unique(X &a){
        sort(all(a));
        a.resize(distance(a.begin(),unique(all(a))));
    }
    template<class T> void smin(T &a, T b) { a = min(a, b); }
    template<class T> void smax(T &a, T b) { a = max(a, b); }
}
using namespace basic;

namespace IO{
    void open(){
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
        #endif
    }
    void close(){
        #ifndef ONLINE_JUDGE
            cerr << "Time elapsed: "<<1000.00 * clock() / CLOCKS_PER_SEC <<" ms.\n";
        #endif
    }
    #ifndef ONLINE_JUDGE
        #define Debug(x) cout<<"ON LINE NUMBER:     "<<__LINE__<<"\t :--> \t"<<#x<<"   =   "<<x<<endl;
        int line=0;
        #define debug(args...){string _s=#args; replace(all(_s),',',' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); line=__LINE__; err(_it, args);}
        void err(istream_iterator<string> it){}
        template<typename T, typename... Args>
        void err(istream_iterator<string> it, T a, Args... args){
            cout<<"ON LINE NUMBER:     "<<line<<"\t :--> \t"<<*it<<"   =   "<<a<<endl;
            err(++it, args...);
        }
    #else
        #define Debug(x)
        #define debug(args...)
    #endif
    template<class T>istream& operator >> (istream& cin,v<T> &a){
        for(auto &i:a)cin>>i;
        return cin;
    }
    istream& operator >> (istream& cin,pll &a){
        cin>>a.f;cin>>a.se;
        return cin;
    }
    istream& operator >> (istream& cin,pii &a){
        cin>>a.f;cin>>a.se;
        return cin;
    }
    template<class X>ostream& operator << (ostream& cout,pair<X,X> &a){
        cout<<a.f<<" "<<a.se<<"\t";
        return cout;
    }
    template<class X>ostream& operator << (ostream& cout,v<X> &a){
        for(auto i:a)cout<<i<<" ";
        return cout;
    }
    template<class X>ostream& operator << (ostream& cout,vv(X) &a){
        for(auto &i:a){cout<<i<<endl;}
        return cout;
    }
    template<class X,class Y>ostream& operator << (ostream& cout,unordered_map<X,Y> &a){
        for(auto &i:a){cout<<i.f<<"\t"<<i.se<<endl;}
        return cout;
    }
    template<class X,class Y>ostream& operator << (ostream& cout,map<X,Y> &a){
        for(auto &i:a){cout<<i.f<<"\t"<<i.se<<endl;}
        return cout;
    }
    template<class X>ostream& operator << (ostream& cout,set<X> &a){
        for(auto i:a)cout<<i<<" ";
        return cout;
    }
    void in(double& x){ 
        string t; cin >> t; x = stod(t);
    } 
    void in(ld& x){
        string t; cin >> t; x = stold(t);
    }
    template<class T> void in(T& x){ cin>>x; }
    template<class X, class... Args> void in(X& first, Args&... rest) { 
        in(first); in(rest...);
    }
    const int precision=1;
    void out(ld& x) { cout << fixed << setprecision(precision) << x << '\n'; }
    template<class T> void out(T x) { cout << x << '\n'; }
    template<class Arg, class... Args> void out(Arg first,Args... rest) { 
        cout << first << ' '; out(rest...);
    }
}
using namespace IO;

int main()
{
    //open();

    string s;cin>>s;
    map<char,int> mp;
    mp[s[0]]++;
    mp[s[1]]++;
    mp[s[2]]++;
    if(mp.size()==1)cout<<"No";
    else cout<<"Yes";

    //close();
    return 0;
}
