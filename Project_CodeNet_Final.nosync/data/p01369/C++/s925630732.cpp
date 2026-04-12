#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	string l="qwertasdfgzxcvb";
	string r="yuiophjklnm";

	int w;   //0:l 1:r
	int cnt;

	while(1){
		cin>>s;
		if (s=="#") break;

		cnt=0;
		if(l.find(s[0])!=-1) w=0;
		else w=1;

		for(int i1=1;i1<s.size();i1++){
			if(l.find(s[i1])!=-1 && w==1){
				cnt++;
				w=0;
			}
			if(r.find(s[i1])!=-1 && w==0){
				cnt++;
				w=1;
			}
		}

		cout<<cnt<<endl;

	}
	return 0;
}