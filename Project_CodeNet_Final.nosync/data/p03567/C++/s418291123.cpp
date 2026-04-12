#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<queue>
#include<math.h>
#include<complex>

using namespace std;


//ユークリッドの互除法　a,bは最大公約数を求めたい２つの数
long long int gcd(long long int a, long long int b) {
             long long int tmp;
             long long int r = 1;
             if (b > a) {
                           tmp = a;
                           a = b;
                           b = tmp;
             }
             r = a % b;
             while (r != 0) {
 
 
                           a = b;
                           b = r;
                           r = a % b;
 
             }
             return b;
}

const long long int mod=1000000007;
int main(){
	long long int n=0;
	string str,str2="CODEFESTIVAL2016";
	cin>>str;
	for(int i=0;i<str.length()-1;i++){
		if(str.substr(i,2)=="AC"){cout<<"Yes"<<endl;return 0;}
	}
	cout<<"No"<<endl;
}
