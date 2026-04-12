#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159265359
#define eps 1e-8
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORN(i,a,b) for(int i=a;i<=b;i++)
typedef long long int ll;
const int INF = 1<<29;
typedef long long ll;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double tick() { 
	static clock_t oldticks;
	clock_t newticks = clock();
	double diff = 1.0 * (newticks - oldticks) / CLOCKS_PER_SEC; 
	oldticks = newticks;
	return diff;
}

bool prime[10000010];
inline void sieve(){
	prime[0]=prime[1]=0;
	for(int i=2;i<10000010;i++)
		prime[i]=1;
	for(int i=2;i<sqrt(10000010);i++){
		if(prime[i]==1){
			for(int j=i*i;j<10000010;j+=i)
				prime[j]=0;
		}
	}
}

inline bool isPrime(ll n){
    if (n <= 1)
        return false; 
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}

inline int toInt(string s){
	//return atoi(s.c_str());
	int x=(int)s[0]-48;
	return x;
}

inline int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

inline int lcm(int a,int b){
	return a*(b/gcd(a,b));
}

inline bool isLeap(int yy){
	return ((yy%4 == 0 && yy%100 != 0) || yy%400 == 0);
}

int main(){
	ios_base::sync_with_stdio(false); //Fast I/O
	cin.tie(NULL);
	//freopen("in.txt","r",stdin);
	//freopen("output.txt","w",stdout);	
	
    char c;
    cin >> c;

    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        cout << "vowel\n";
    else
        cout << "consonant\n";
	
    //cerr << tick();

	return 0;
}
