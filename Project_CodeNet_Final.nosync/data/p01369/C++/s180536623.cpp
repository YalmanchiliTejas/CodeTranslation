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


const long long int mod=1000000007;
const long long int INF=99999999999999999;

long long int n,m,p;
string s;

int main() {
	cout << fixed << setprecision(18);
	cin>>s;
	//             a b c d e f g h i j k l m n o p q r s t u v w x y z
	int chang[30]={0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,1,0};
	while(s!="#"){
		long long int cou=0;
		for(int i=1;i<s.length();i++){
			if(chang[s[i]-'a']!=chang[s[i-1]-'a']){cou++;}
		}
		cout<<cou<<endl;
		cin>>s;
	}
	
} 
