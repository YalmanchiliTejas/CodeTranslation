//#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
using namespace std;
#define vec vector
#define fi first
#define se second
#define eb emplace_back
#define ef emplace_front
#define pof pop_front()
#define pob pop_back()
#define mp make_pair
#define Rep(i,n) for(li i=0,nn=(li)(n);i!=nn;++i)
#define Rep1(i,n) for(li i=1,nn=(li)(n)+1;i!=nn;++i)
#define rRep(i,n) for(li i=n-1;i>=0;--i)
#define rRep1(i,n) for(li i=n;i>=1;--i)
#define each(x,v) for(auto x:v)
#define eachitr(it,v) for(auto it=v.begin();it!=v.end();++it)
#define eachritr(it,v) for(auto it=v.rbegin();it!=v.rend();++it)
#define Size(v) (li)(v.size())
#define SortA(v) sort(v.begin(),v.end())
#define SortD(v) sort(v.rbegin(),v.rend())
#define All(a) (a).begin(),(a).end()
#define input(a) for(li ii=0,nn=(li)(a.size());ii!=nn;++ii){cin>>(a).at(ii);}
#define input2(a,b) for(li ii=0,nn=(li)(a.size());ii!=nn;++ii){cin>>(a).at(ii)>>(b).at(ii);}
using li = int64_t;
using intl = int64_t;
using ld = long double;
using vi = vec<li>;
using vb = vec<bool>;
using vd = vec<ld>;
using vvi = vec<vi>;
using qi = deque<li>;
using vqi = vector<qi>;
using pqi = priority_queue<li>;
using pi = pair<li, li>;
using vpi = vec<pi>;
using si = set<li>;
using vsi = vec<si>;
using mii = map<li, li>;
using vmii = vec<mii>;
vec<li> dx = {0, 1, 0, -1, 1, 1, -1, -1};
vec<li> dy = {1, 0, -1, 0, 1, -1, 1, -1};
constexpr li INF = LLONG_MAX;

template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

void Yes(bool b) {
	if (b)cout << "Yes";
	else cout << "No";
}
void yes(bool b) {
	if (b)cout << "yes";
	else cout << "no";
}
void YES(bool b) {
	if (b)cout << "YES";
	else cout << "NO";
}

queue<string> argment_contents;
void set_args_con() {}
template<class First, class... Rest>
void set_args_con(const First& first, const Rest&... rest) {
	stringstream ss;
	ss << first;
	argment_contents.push(ss.str());
	set_args_con(rest...);
}
string gen_string(string s) {
	s += ',';
	string ret = "";
	int par = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == '(' || s[i] == '<' || s[i] == '{') par++;
		else if (s[i] == ')' || s[i] == '>' || s[i] == '}') par--;
		if (par == 0 && s[i] == ',') {
			ret += "=" + argment_contents.front();
			argment_contents.pop();
			if (i != (int)s.size() - 1) {
				ret += ",";
			}
		}
		else ret += s[i];
	}
	return ret;
}
#define dump(...) {set_args_con(__VA_ARGS__);cerr<<gen_string(#__VA_ARGS__)<<endl;}



/* //__int128用
using lli = __int128;
std::ostream &operator<<(std::ostream &dest, __int128_t value) {
  std::ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = std::end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = std::end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(std::ios_base::badbit);
    }
  }
  return dest;
}

__int128 parse(string &s) {
  __int128 ret = 0;
  for (int i = 0; i < s.length(); i++)
    if ('0' <= s[i] && s[i] <= '9')
      ret = 10 * ret + s[i] - '0';
  return ret;
}
*/

//mod用
constexpr li mod = 998244353;

intl modpow(intl a, intl n, intl p) {
	intl res = 1;
	while (n > 0) {
		if (n & 1) {res = (res * a) % p;}
		a = (a * a) % p;
		n >>= 1;
	}
	return res;
}

intl modinv(intl a, intl p) {
	if (a == 0) {
		cout << "/0 at modinv" << endl;
		exit(0);
	}
	if (a < 0) {
		cout << "/- at modinv" << endl;
		exit(0);
	}
	if (a == 1) {return 1;}
	if (a > p) {return modinv(a % p, p);}

	return p - ( modinv(p % a, p) * (p / a) ) % p;
}

intl modcomb(intl n, intl k, intl p) {
	if (k > n || k < 0 || n < 0) {
		cout << "error at modcomb" << endl;
		exit(0);
	}
	if (2 * k > n) { k = n - k;}
	if (k == 0) {return 1;}
	intl c = 1;
	for (intl i = 0; i < k; i++) {
		c = ( c * ( (n - i) % p ) % p ) * modinv(i + 1, p) % p;
	}
	return c;
}




int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.precision(16);

	li N,X,M;cin>>N>>X>>M;

	vi m(M+1);
	si ms;
	li ans=0;

	li rs,re;
	bool broken=0;

	Rep1(i,N){
		m[i]=X;
		ms.insert(X);
		X*=X;
		X%=M;

		if(ms.count(X)){
			rs=find(m.begin()+1,m.end(),X)-m.begin();
			re=i;
			broken=1;
			break;
		}
	}
	if(!broken){
		cout<<accumulate(m.begin()+1,m.begin()+N+1,0LL);return 0;
	}

	ans+=accumulate(m.begin()+1,m.begin()+rs,0LL);
	N-=rs-1;
	ans+=(N/(re-rs+1))*accumulate(m.begin()+rs,m.begin()+re+1,0LL);
	N%=re-rs+1;
	ans+=accumulate(m.begin()+rs,m.begin()+rs+N,0LL);

	cout<<ans;






}