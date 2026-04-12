
/*
	Author : SummerPark ~ 2019	
*/

#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp> 
//using namespace __gnu_pbds; 
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;

//methods: find_by_order(k); & order_of_key(k);
//To make it an ordered_multiset, use pairs of (value, time_of_insertion)
//to distinguish values which are similar

#define int long long
#define pb push_back
#define ppb pop_back
#define vi vector<int>
#define ed end()
#define bg begin()
#define sz size()
#define ln length()
#define all(x) x.begin(),x.end()
#define allp(x,n) x,x+n
#define endl "\n"
#define NL cout<<'\n';
#define F first
#define S second
#define disp(x) for(auto t : x )cout<<t<<" ";
#define for0(n) for(int i=0;i<n;i++)
#define for0j(n) for(int j=0;j<n;j++)
#define SS <<" "<<
#define arrin(a,n) vi a(n);for0(n){cin>>a[i];}
#define pf(x) cout<<x<<endl;
#define Check pf("Check")
#define gridin(num,n,m) for0(n){for0j(m) cin>>num[i][j];}
#define dispgrid(num,n,m) for0(n){for0j(m) cout<<num[i][j]<<" "; cout<<endl;}
#define tk(a) int a;cin>>a;
#define tk2(a,b)tk(a)tk(b)
#define tk3(a,b,c)tk2(a,b)tk(c)
#define tk4(a,b,c,d)tk2(a,b)tk2(c,d)
#define tk5(a,b,c,d,e)tk4(a,b,c,d)tk(e)
#define tk6(a,b,c,d,e,f)tk3(a,b,c)tk3(d,e,f)
#define tk7(a,b,c,d,e,f,g)tk6(a,b,c,d,e,f)tk(g)
#define tk8(a,b,c,d,e,f,g,h)tk7(a,b,c,d,e,f,g)tk(h)
#define YES cout<<"YES"<<endl;
#define Yes cout<<"Yes"<<endl;
#define NO cout<<"NO"<<endl;
#define No cout<<"No"<<endl;
#define yes cout<<"yes"<<endl;
#define no cout<<"no"<<endl;
#define pii pair<int,int> 
#define vpii vector<pii>
#define acum accumulate
#define fmap gp_hash_table
#define LONG LLONG
const int MOD=1000000007;
const int N=100000;


unsigned hash_f(unsigned x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}

 
struct chash {
    const int RANDOM = (long long)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now().time_since_epoch().count();
    static unsigned long long hash_f(unsigned long long x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
    int operator()(int x) const { return hash_f(x)^RANDOM; }
};

struct pairhash {
    int operator()(pii x) const { return hash_f(x.F) * 31 + hash_f(x.S); }
};
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
            return os << "(" << p.first << ", " << p.second << ")";
}
template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
            os << "{";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "}";
}
template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "]";
}
template < typename T >
ostream &operator << ( ostream & os, const multiset< T > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "]";
}
template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << it -> first << " = " << it -> second ;
                                            }
                    return os << "]";
}

// To find number of elements less than k in array a
// answer would be int res = upper_bound(all(a),k) - a.bg

// To find number of elements greater than k in array a
// answer would be int res = a.ed - upper_bound(all(a),k)


int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	string a;
	cin >> a;
	set<char> s(all(a));
	if(s.sz==1){
		No
	}     else{
		Yes
	}
	return 0;
}