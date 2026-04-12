#include<iostream>
#include<string>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

int main(){
	string s;
	while(cin>>s,s!="#"){
		bool alphabet[26];
		loop(i,0,(int)('h'-'a'))alphabet[i]=0;
		loop(i,(int)('h'-'a'),(int)('q'-'a'))alphabet[i]=1;
		loop(i,(int)('q'-'a'),26){
			if(i==(int)('u'-'a')||i==(int)('y'-'a'))alphabet[i]=1;
			else alphabet[i]=0;
		}
		int cnt=0;
		rep(i,s.size()-1){
			if(alphabet[(int)(s[i]-'a')]!=alphabet[(int)(s[i+1]-'a')])cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
