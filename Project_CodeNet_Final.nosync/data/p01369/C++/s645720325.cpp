#include<iostream>
#include<algorithm>
#include<list>
#include<string>
using namespace std;
int main(){
	list<char> left={'q','w','e','r','t','a','s','d','f','g','z','x','c','v','b'};
	list<char> right={'y','u','i','o','p','h','j','k','l','n','m'};
	bool flag;
	while(1){
		string str;
		int cnt=0;
		cin >> str;
		if(str=="#")	break;
		if(find(right.begin(),right.end(),str[0])!=right.end())	flag = false;
		else flag = true;
		for(int i=1;i<str.size();i++){
			if(find(right.begin(),right.end(),str[i])!=right.end()){
				if(flag)	cnt++;
				flag = false;
			}
			else{
				if(!flag)	cnt++;
				flag =true;
			}
		}
		cout << cnt << endl;
	}
}
