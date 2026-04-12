#include<iostream>
#include<string>

using namespace std;
int main()
{
	int j=0,n,i,k;
	cin >> n;
	int p[100]={};
	string str,push,pop,quit,move,c,b[100][1000]={};//101にすると０からはじめても１００こあるからi-1にしなくてよい
	while(1){
		cin >> str;
		if(str=="quit"){break;}
		else if(str=="push"){
			cin >> i >> c;
			b[i-1][p[i-1]]=c;
			p[i-1]++;
		}else if(str=="pop"){
			cin >> i;
			cout << b[i-1][p[i-1]-1] << endl;
			p[i-1]--;
		}else if(str=="move"){
			cin >> i >> k;
			b[k-1][p[k-1]]=b[i-1][p[i-1]-1];
			p[i-1]--;
			p[k-1]++;
		}
	}
	return 0;
}










		
		