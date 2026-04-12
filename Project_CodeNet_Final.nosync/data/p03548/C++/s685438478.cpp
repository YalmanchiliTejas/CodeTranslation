//#define debug //*******************************************************************************************************************************************

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// [Tips]
// XCodeでのEOF入力はCtrl+D
// ¥はAlt+\
// ansは結構INTの範囲2,147,483,647を超えることがあるのでlong long使っておいたほうが良い
// ２進数表示 = dout << static_cast<bitset<8> >(x)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////
//
////////////////////////////////////////


#ifdef debug
#include <chrono>
#endif

#include <iostream>
#include <algorithm> // next_permutation
#include <iomanip>
#include <cmath>
#include <vector>
#include <sstream>
#include <string>
#include <cstring> //memcpy
#include <cstdio>
#include <stack>
#include <queue>
#include <list>
#include <numeric> //accumulate
#include <map>
//#include <unordered_map> //hash func.
#include <fstream> //ifstream, ofstream
#include <iterator> //insert_iterator::inserter
#include <set>


//#define NDEBUG //If NDEBUG is defined before #include <cassert>, assert will be ignored. You had better define NDEBUG when u submit the code.
#include <cassert> //assert

using namespace std;


#define dout cout
//If u wanna output to a text file instead of standard output, plz define OUTPUTFILE.
//#define OUTPUTFILE "output.txt" //************************************************************
#ifdef OUTPUTFILE
#define dout outputfile
ofstream outputfile(OUTPUTFILE);
#define OutputFilePath "/Users/Nag/Documents/Prgm/Test/DerivedData/Test/Build/Products/Debug/output.txt"
#endif


#define din cin
//If u wanna input from a text file instead of standard input, plz define INPUTFROMTEXTFILEを.
//#define INPUTFILE "input.txt" //**************************************************************
#ifdef INPUTFILE
#define din inputfile
ifstream inputfile(INPUTFILE);
#endif

#define scand(A) scanf("%d", &(A))
#define scans(A) scanf("%s", (A))
#define printd(A) dout << "%d\n", (A))
#define prints(A) dout << "%s\n", (A))
#define disp(A) dout << #A << " = " << setw(3) << (A) << endl
#define disP(A) dout << setw(3) << (A) << " "
#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define show(A,s,g) dout << #A << " = "; rep(__w, (s), (g)) {disP(A[__w]);} dout << endl
#define showi(A,s,g) dout << #A << " = "; rep(__w, (s), (g)) {disP(__w);} dout << endl
#define line  dout << "----------------\n"
#define line2 dout << "================\n"

#define sign(x) ((x)>0)-((x)<0) //x<0: -1, x=0: 0, x>0: +1
#define p(i) ((i)/2)
#define l(i) ((i)*2)
#define r(i) ((i)*2+1)
#define sibling(i) (i^1) //the other sibling of i (ex. 16^1 = 17, 17^1 = 16)
#define isRightChild(i) (i&1) // ex. 16&1 = 0, 17&1 = 1
#define isLeftChild(i) (!(i&1)) // ex. 16&1 = 1, 17&1 = 0


typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;

const int INF = (1LL<<31)-1;
//const int NONE = -1;
//const ll INF_LL = (ll)9e18-1LL; //Be careful for overflow.
//const ull INF_ULL = (ull)1e19-1ULL;
//#define MOD 1000000007 //大きい素数の代表といえばこの人、10億7さん

#define N_MAX 100010 //num of vertex or element
//#define M_MAX 124760 //num of edge
//#define DATA_MAX 1010



void display() {
#ifdef debug
    dout << "------------------------- display() ---------------------\n";
    
    //    dout << "   "; showi(j,0,N+1);
    //    dout << "C[][] = \n";
    //    rep(i,0,N+1) {
    //        disP(i); dout << " : ";
    //        rep(j,0,N+1) {
    //            disP(C[i][j]);
    //        }
    //        dout << endl;
    //    }
    //    dout << endl;
    

    
    dout << "------------------------- end of display() ---------------------\n";
#endif
}






int main() {
    
    //cin, coutの高速化  ＊注意：cinを使うなら全部cinで、scanfを使うなら全部scanfで統一するように！
    cin.tie(0); //cinとcoutの同期を切る
    ios::sync_with_stdio(false); //iostreamとstdioの同期を切る
    
    //read input data

    
    //------------------------------------------------------------------------------------------
#ifdef debug
    //start timer
    auto startTime = chrono::system_clock::now();
#endif
    //------------------------------------------------------------------------------------------
    
    
    int X, Y, Z;
    din >> X >> Y >> Z;
    
    dout << (X-Z)/(Y+Z) <<endl;
    
  
    
    
#ifdef debug
    dout << "=== OUTPUT ===\n";
#endif
    
    
    
    
    
    
    
    
    
    
    
    //------------------------------------------------------------------------------------------
#ifdef debug
    //stop timer
    auto endTime = chrono::system_clock::now();
    auto dur = endTime - startTime;
    auto msec = chrono::duration_cast<chrono::milliseconds>(dur).count();
    dout << fixed << setprecision(4) << (double)msec/1000 << " sec \n";
#ifdef OUTPUTFILE
    cout << fixed << setprecision(4) << (double)msec/1000 << " sec \n";
#endif
#endif
    //------------------------------------------------------------------------------------------
    
#ifdef INPUTFILE
    inputfile.close();
#endif
    
#ifdef OUTPUTFILE
    outputfile.close();
    cout << "\"" << OutputFilePath << "\"" << endl;
#endif
    
    return 0;
}