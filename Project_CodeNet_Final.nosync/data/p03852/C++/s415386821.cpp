#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <vector>
 
using namespace std;
typedef long long ll;


ll ans,mx,mn,sum;
int main(){
	string s;
	cin>>s;
	if(s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u'){
		cout<<"vowel";
	}
	else cout<<"consonant";
}