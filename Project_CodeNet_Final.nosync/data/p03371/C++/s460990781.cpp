#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>
#include<random>
#include<ctime>
#include<set>

using namespace std;
#define SAY_YES cout<<"YES"<<endl;
#define SAY_Yes cout<<"Yes"<<endl;
#define SAY_NO cout<<"NO"<<endl;
#define SAY_No cout<<"No"<<endl;
#define IFYES(TRUE_OR_FALSE) if(TRUE_OR_FALSE){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;} 
#define IFYes(TRUE_OR_FALSE) if(TRUE_OR_FALSE){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;} 
#define IFyes(TRUE_OR_FALSE) if(TRUE_OR_FALSE){cout<<"yes"<<endl;}else{cout<<"no"<<endl;} 
#define DEBUG_OUTPUT_ARRAY(XXX,ONE) for(int i=0;i<(ONE);i++){cout<<"DEBUG: i = "<<i<<" -> "<<XXX[i]<<endl;}
#define DEBUG_OUTPUT_ARRAY2(XXX,ONE,TWO) for(int i=0;i<(ONE);i++){cout<<"<<< i = "<<i<<" >>>"<<endl;for(int j=0;j<(TWO);j++){cout<<"DEBUG: j = "<<j<<" -> "<<XXX[i][j]<<endl; } }
#define DEBUG_OUTPUT_ARRAY2_BOX(XXX,ONE,TWO) for(int i=0;i<(ONE);i++){cout<<i<<"  ";for(int j=0;j<(TWO);j++){cout<<XXX[i][j]<<" "; } cout<<endl;}

typedef pair<long long int,long long int> pll;


const long long int mod=1000000007;
const long long int INF=99999999999999999;


long long int A,B,C,X,Y;
string str,resstr;
int main() {
	cout << fixed << setprecision(18);
    
    cin>>A>>B>>C>>X>>Y;
    //cout<<min({2*C*max(X,Y),A*X+B*Y,2*C*Y+max(A*(X-Y),0LL),2*C*X+max(B*(Y-X),0LL)})<<endl;
    
    if((2*C<=A&&X>Y)||(X<Y&&2*C<=B)){
        cout<<2*C*max(X,Y)<<endl;
        return 0;
    }
    if(2*C>=A+B){
        cout<<A*X+B*Y<<endl;
        return 0;
    }
    if(2*C<A+B&&(2*C>A||2*C>B)){
        if(X>=Y){
            cout<<2*C*Y+A*(X-Y)<<endl;
            }
        else{
            cout<<2*C*X+B*(Y-X)<<endl;
            }
    }
    
} 
