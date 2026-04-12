//Relive your past life.
//Face your demons.
//The past is never dead,it is not even past.
//The memories are not only the key to the past but...also to the future.
//coded in Rusty Lake
#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
string s;
int n,d,f[11111][111][2],a[11111];
void u(int &x,int y){
    x+=y;
    if(x>=orz)x-=orz;
}
int main(){
    cin>>s;
    cin>>d;
    n=s.size();
    for(int i=0;i<n;++i)a[i]=s[i]-48;
    f[0][0][1]=1;
    for(int i=0;i<n;++i){
        for(int j=0;j<d;++j){
            u(f[i+1][(j+a[i])%d][1],f[i][j][1]);
            for(int k=0;k<a[i];++k)u(f[i+1][(j+k)%d][0],f[i][j][1]);
            for(int k=0;k<10;++k)u(f[i+1][(j+k)%d][0],f[i][j][0]);
        }
    }
    int ans=orz-1;
    u(ans,f[n][0][0]);
    u(ans,f[n][0][1]);
    cout<<ans<<endl;
	//system("pause");
	return 0;
}
