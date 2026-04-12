#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <set>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

using namespace std;
typedef long long int lli;

int main(){
	char c;
	cin>>c;
	if(c=='a'||c=='i'||c=='u'||c=='e'||c=='o') cout<<"vowel";
	else cout<<"consonant";
}