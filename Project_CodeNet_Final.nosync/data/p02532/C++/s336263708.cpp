#include<iostream>
#include<string>

using namespace std;
int main()
{
	int j=0,n,i,k;
	cin >> n;
	int p[101]={};
	string str,push,pop,quit,move,c,b[101][1001]={};
	while(1){
		cin >> str;
		if(str=="quit"){break;}
		else if(str=="push"){
			cin >> i >> c;
			b[i][p[i]]=c;
			p[i]++;
}else if(str=="pop"){
			cin >> i;
			cout << b[i][p[i]-1] << endl;
			p[i]--;
}else if(str=="move"){
			cin >> i >> k;
			b[k][p[k]]=b[i][p[i]-1];
			p[i]--;
			p[k]++;
}
}
	return 0;
}