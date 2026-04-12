    //#pragma GCC optimize("Ofast")
	//#pragma GCC target("avx,avx2,fma")
	//#pragma GCC optimization ("unroll-loops")
	
    #include<bits/stdc++.h>
    using namespace std;
	
    #define ll long long
    #define ull unsigned long long
    #define ld long double
    #define ff first
    #define ss second
    #define null NULL
    #define MAX 1000000000  // 1x10^9
    #define all(c) (c).begin(),(c).end()
    #define eb emplace_back
    #define pb push_back
    #define pf push_front
    #define lb lower_bound   //used for sortted 
    #define ub upper_bound 
    #define m_p make_pair      
    #define mod 1000000007
    #define For(i,n) for(int i=(0);i<(n);++i)
    #define FOR(i,a,b) for(int i=(a);i<=(b);++i)
	#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
    #define in(s3) inserter((s3), (s3).begin())  //	set_union(all(s1),all(s2),in(s3));
    typedef vector<ll> vl;
    typedef vector< vl > vvl;
    typedef pair< ll,ll> pll;
    typedef map< ll,ll> mll;
    
    //  A-65 Z-90 a-97 z-122   A-a = 32   Z-A = z-a = 35
    //	v.push_back(make_pair(min(2 * k[i], l[i]) - min(k[i], l[i]), i));      //int pos = v[i].second;
    //	floor(log10(no) + 1);                   //	to_string(no).length();             ----- length of a number
	//  llabs - long long of abs
	//  labs -long of abs
	//  sqrtf - sq root of float
	//  sqrtl - sq of long double    ( cout << fixed << setprecision(12) << sqrtl(val2) << endl; )
	//  it = find (all(vec), e);     if(it != vec.end());       it - vec.begin();
   	//	size_t found = str.find(str1);    if(found != string::npos); 	 cout<<found;
    	 
	/*	
		1. ^ is XOR and is used to to check odd occurance of number as a number XORed with itself results in zero so all even	occurrances result in zero.
		2.   & is used to check even or odd. (x & 1) ? printf("Odd") : printf("Even"); 
		3.   left shift(<<) - *         right shift(>>) - /
		4.   int a[] = { 1, 7, 2, 4, 8, 3 }; 
    		 int l = sizeof(a) / sizeof(a[0]); 
    		 sort(a, a + l);  reverse(a, a + l); accumulate(a, a + l, 0); *max_element(a, a + l);
	*/
	
	string to_string(char& x) {      
		string s(1,x);
		return s;    
	} 
	struct obj {
		ull val1;
		ull val2;
		ull pos;
	};
	bool cmp(const pair<int,int>&a,const pair<int,int>&b) {
		if(a.first==b.first)
		return a.second<b.second;
		return a.first<b.first;
	}

	int main() {
		ull sum=0,n,no,sum1=0,total=0;
		vector<ull> v;
		cin>>n;
		while(n--)
		{
			cin>>no;
			v.pb(no);
		}
		
		for(ull i=0;i<v.size();i++)
		{
			sum=(sum+v[i])%mod;
		}
		
		for(ull i=0;i<v.size();i++)
		{
			sum1=(sum1+v[i])%mod;
			total=(total+((v[i]*(sum-sum1+mod)%mod)%mod))%mod; //wrong due to this line as sum can be less than sum1 so sum-sum1 is not appropriate.
			
		}
		cout<<total;
		return 0;
	}
/*
		ll n;
		cin>>n;
	   ll a;
	   ll sum=0,ans=0;
	   for(ll i=0;i<n;i++){
		cin>>a;

		ans=(ans+((sum*a)%mod))%mod;
	   
		sum=(sum+a)%mod;
	   }
	   cout<<ans<<endl;
	   return 0;
*/
