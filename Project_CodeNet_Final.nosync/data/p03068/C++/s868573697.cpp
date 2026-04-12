#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
int N;
string s;
int K;
cin>>N>>s>>K;
for(int i=0;i<N;i++){
	if(s[i]!=s[K-1])
	s[i] = '*';
}
cout<< s <<endl;


}
