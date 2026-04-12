#include <iostream>
using namespace std;

int main() {
int i[101]={0},num,from,to,n;
cin>>n;
string a[105][1000];
string moji,co;
while(cin>>moji){
if(moji=="quit"){
break;
}
if(moji=="push"){
cin>>num>>co;
a[num][i[num]]=co;
i[num]=i[num]+1;
}
if(moji=="move"){
	cin>>from>>to;
	a[to][i[to]]=a[from][i[from]-1];
	i[to]=i[to]+1;
	i[from]=i[from]-1;
}
if(moji=="pop"){
	cin>>num;
cout<<a[num][i[num]-1]<<endl;
i[num]=i[num]-1;
}
}


	return 0;
}