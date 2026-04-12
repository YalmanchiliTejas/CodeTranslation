// author-Shivam gupta

#include <bits/stdc++.h>


using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))

#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)

#define IN(A, B, C) assert( B <= A && A <= C)

#define MP make_pair
#define FOR(i,a) for(int i=0;i<a;i++)

#define FOR1(i,j,a) for(int i=j;i<a;i++)

#define EB emplace_back

#define INF (int)1e9

#define EPS 1e-9

#define PI 3.1415926535897932384626433832795

#define MOD 1000000007

#define read(type) readInt<type>()
#define max1 100001
#define out(x) cout<<x<<'\n'
#define out1(x) cout<<x<<" "
#define END cout<<'\n'
const double pi=acos(-1.0);

typedef pair<int, int> PII;

typedef vector<int> VI;

typedef vector<string> VS;

typedef vector<PII> VII;

typedef vector<VI> VVI;

typedef map<int,int> MPII;

typedef set<int> SETI;

typedef multiset<int> MSETI;

typedef long int li;

typedef unsigned long int uli;

typedef long long int ll;

typedef unsigned long long int  ull;

bool isPowerOfTwo (int x)
{
  /* First x in the below expression is
    for the case when x is 0 */
  return x && (!(x&(x-1)));
}
void fast(){
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
}
ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
ll modInverse(ll n, ll p)
{
    return power(n, p-2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
ll ncr(ll n, ll r,ll p)
{
   // Base case
   if (r==0)
      return 1;

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    ll fac[n+1];
    fac[0] = 1;
    for (ll i=1 ; i<=n; i++)
        fac[i] = fac[i-1]*i%p;

    return (fac[n]* modInverse(fac[r], p) % p *
            modInverse(fac[n-r], p) % p) % p;
}



ll fastexp (ll a, ll b, ll n) {
  ll res = 1;
  while (b) {
      if (b & 1) res = res*a%n;
      a = a*a%n;
      b >>= 1;
  }
  return res;
}

vector<ll> f, ifa;

int main() {
  string a;
  cin>>a;
  if(a[0]==a[1] && a[1]==a[2]){out("No");}
  else {out("Yes");}




}
/*

           .$                                  $.
          /:;                                  :;\
         : $                                    $ ;
         ;:$                                    $;:
        : $:              ________              ;$ ;
        ; $;;     _..gg$$SSP^^^^T$S$$pp.._     ::$ :
       : :$;|  .g$$$$$$SSP"      "TS$$$$$$$p.  |:$; ;
       ; :$;:.d$$$$$$$SSS          SS$$$$$$$$b.;:$; :
      :  :$$$$$$$$$$$$SSS          SS$$$$$$$$$$$$$;  ;
      ;  $$$$$$$$$$$$$$SSb.      .dS$$$$$$$$$$$$$$;  :
     :  :S$$$$$$$$$$$$$$SSSSppggSSS$$$$$$$$$$$$$$$;   ;
     |  :SS$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$;   :
     |  :SS$$$$$$$$$$$$$$$$$^^^^^^^^^$$$$$$$$$$$$$$   :
     ;   SS$$$$$$$$$$P^"                 "^T$$$$$$$   :
    :    :SS$$$$$$$$$                       T$$$$$;   :
    |     SSS$$$$$$$;                        T$$$$    :
    |     :SSS$$$$$$;                        :$$$;    :
    ;      SSS$$$$$$;                        :S$$;    :
    ;      :SS$$P"^P                          S$$;    :
    ;    ..d$$$P    `                         S$$$    :
    ;     T$$$P                          dS   T$$$b.  :
    ;    :$$$$.     .                   dSS;   $$$$$b.:
    ;    :$$$$$b     Tb.   .          .dSS$$b.d$$$$$$$:
    :    $$$$$$$b     TSb   Tb..g._, :$$SS$$$$$$SSS$$$:
    :   :$$$$$$$$b     SSb   T$SS$P   "^TS$$$$$$P"TS$$:
    :   $$$$$$$$$$b._.dS$$b _ T$$P _     TSS$SSP  :SS$:
    :  :$$$$SSS$$$$$$$$$P" d$b. _.d$P     TSSP"    SS$:
    :  :P"TSSP"^T$$$$$$P  :$$$$$$$$P d$$b          $S$;
    :  :b.dS^^-.  ""^^"    $b T d$$$s$$$$b __..--""$ $;
    :  :$$$S    ""^^..ggSS$$$$$$$$$$$$$$P^^""     .$ $;
    :   $$$$$pp..__   `j$$$$$$^$$$$$b. d....ggppTSSS$$;
    :   $$$$SP     """t  :$$$$ $$$$$$$b.  d$b    `TSS$;
    :  \:$$SP   _.gd$$P_d$$$$$ $$$$$$$$$bd$P'    .dSPd;
    :   \"^S     "^T$$$$$$$$$$ $$$$$SS$$$$b.    dSS'd$;
    $    $. "-.__.gd$$$$$$$SP:S$$P  TSS$$$$$bssS^".d$$:
   :$    $$b.   ""^^T$$$$SP' :S$P    TSSSP^^""  .d$$$$:
   :$   :$$$P        "^SP'   :S;     .^"`.     $$$$$$$:
   $;   :$$$            "-.  :S;  .-"     \    :$$$$$$:
  .$ :  $$$;   :           `.:S;.'         ;    $$$$$$:;
 .P :S  $$$    ;             `^'                :$$$$$:;
.P  S;.d$$;   :               -'                 $$$$$:;
$  :SS$$$$    ;     __....----  --...____        :$$$ :S
$  $SSS$$;    :  ; d$$$$$$$pppqqqq$$$$$$L;       :$$$ SS
: :SSSSS$$     ; : \ "^T$$$$$$$$$$$$$P' .':      $PT$ SS;
 $SP^"^TSP\    :  \ "-.  """"""""""" .-"  ;     /   $ SSSb.
 :S     S  \           "--...___..--"    /  :  /    :gSSSSSb.
  T bug T   \       `.      _____       /   ; /
   `         \ :      "==="""""""""===""   : /
              `:                           ;'
                "-.                     .-"
                   ""--..         ..--""
*/
