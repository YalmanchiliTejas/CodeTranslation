//-----Sakib-----//
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#include<cstdlib>
using namespace std;

// - - - - - - Data Types - - - - - - //

#define SF1(A)              scanf("%d", &A)
#define SF2(A,B)            scanf("%d %d", &A, &B)
#define SF3(A,B,C)          scanf("%d %d %d", &A, &B, &C)

typedef long long int LLI;
typedef unsigned long long int ULL;
#define SL1(A)              scanf("%lld", &A)
#define SL2(A,B)            SL1(A);SL1(B)
#define SL3(A,B,C)          SL2(A,B);SL1(C)

#define SD1(A)              scanf("%lf", &A)
#define SD2(A,B)            SD1(A);SD1(B)
#define SD3(A,B,C)          SD2(A,B);SD1(C)

// - - - - - - Vectors - - - - - - //
typedef vector<int> VI;
typedef vector<LLI> VLLI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<VI> VVI;
typedef vector<VS> VVS;

#define scanVI(V, N)        for(int I=0; I<N; I++){ int X; SF1(X); V.PB(X); }
#define scanVLLI(V, N)      for(int I=0; I<N; I++){ LLI X; SL1(X); V.PB(X); }
#define scanVS(V, N)        for(int I=0; I<N; I++){ string X; cin >> X; V.PB(X); }
#define scanVD(V, N)        for(int I=0; I<N; I++){ double X; SD1(X); V.PB(X); }

// - - - - - - Maps - - - - - - //
typedef map<int, int> MII;
typedef map<int, string> MIS;
typedef map<int, char> MIC;
typedef map<string, int> MSI;
typedef map<char, int> MCI;
typedef map<int, VI> MIVI;

// - - - - - - Pairs - - - - - - //
typedef pair<int, int> PII;
typedef pair<string, string> PSS;
typedef pair<char, char> PCC;
typedef pair<int, string> PIS;
typedef pair<int, char> PIC;
typedef pair<string, char> PSC;
typedef pair<LLI, LLI> PLL;

// - - - - - - Sets - - - - - - //
typedef set<int> SI;
typedef set<LLI> SLLI;
typedef set<string> SS;
typedef set<char> SC;
// - - - - - - - - - - - - - - - - - - //

//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#define PF                  printf
#define SF                  scanf
#define PB                  push_back
#define SR(N)               right<<setw(N)
#define SL(N)               left<<setw(N)
#define PREC(N)             fixed << setprecision(N)
#define POP                 pop_back()
#define PP                  prev_permutation
#define NP                  next_permutation
#define MP                  make_pair
#define CLRN(a, b)          memset(a, b, sizeof(a))
#define CLR(a)              memset(a, 0, sizeof(a))
#define ALL(a)              a.begin(), a.end()
#define ALLN(a, n)          (a, a+n)
#define BSRCN(a, n, x)      binary_search(ALLN(a, n), x)
#define BSRC(a, z)          binary_search(ALL(a), z)
#define MAX                 10000007
#define MIN                 -10000007
#define PI                  acos(-1)
#define BR                  puts("")
#define FastIO              { ios_base::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr); }
#define READ()              freopen("input.txt", "r", stdin)
#define WRITE()             freopen("output.txt", "w", stdout)
#define IO                  READ(); WRITE();
#define SEED                srand((rand()-time(NULL)))
#define ran()               (((((1ULL*rand())<<31)|(1ULL*rand()))<<13)^((((1ULL*rand())<<32)|(1ULL*rand()))))
#define rran(a, b)          ((ran() % ((b) - (a) + 1)) + (a))
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
/*----------------------Graph Moves----------------*/
int ROW[]={+1,-1,+0,+0};
int COL[]={+0,+0,+1,-1};

int X[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
int Y[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move

int KX[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
int KY[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move

int basePrime[]={1009, 1013, 1019, 1021, 1031, 1223, 1229, 1231, 1237, 1249, 1289, 1291, 1297, 1301, 1303, 353, 359, 367, 373, 379, 859, 863, 877, 881, 883,
                1931, 1933, 1949, 1951, 1973, 401, 409, 419, 421, 431, 1709,  1721, 1723, 1733, 1741, 3499, 3511, 3517, 3527, 3529, 929, 937, 941, 947, 953};

/*----------------------------------------------------------------------------------------------------------------------------------------------*/

template<class XXX> XXX GCD(XXX a, XXX b) { return b == 0 ? a : GCD(b , a % b); }
template<class XXX> XXX LCM(XXX a, XXX b) { return a * (b/GCD(a, b)); }
bool CMP(LLI a, LLI b) { return a>b; }
template<class XXX> void fastread(XXX &number){ bool negative = false; register XXX c; number = 0; c=getchar();
if (c=='-') { negative = true; c=getchar(); }
    for (; (c>47 && c<58); c=getchar()) number = number *10 + c - 48;
    if (negative)number *= -1;
}
template<class XXX> inline XXX moduler(XXX num, XXX mod) {return (num>=mod?num-=mod:num);}

/// BITMASK
int Set(int N,int pos){return N=N | (1<<pos);}
int Reset(int N,int pos){return N= N & ~(1<<pos);}
bool Check(int N,int pos){return (bool)(N & (1<<pos));}

void OPFILE(){
    #ifdef gHost
        freopen("D:\\OneDrive - Daffodil International University\\Programming\\CPP\\input.txt", "r", stdin);
        freopen("D:\\OneDrive - Daffodil International University\\Programming\\CPP\\output.txt", "w", stdout);
    #endif
}
//clock_t Start=clock(); void Time(){ printf("\n>>Runtime: %.10fs\n", (double) (clock() - Start) / CLOCKS_PER_SEC); }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - END - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //

int main()
{
    OPFILE();

    int n; cin >> n;
    puts((n>=30?"Yes":"No"));

    return 0;
}
