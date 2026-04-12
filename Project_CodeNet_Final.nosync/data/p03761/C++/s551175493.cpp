#include <iostream>
#include <string>
using namespace std;
int flag[50][26];
int getMin(int j,int n)
{
	int minV=50;
	for (int i=0;i<n;i++){
		if (minV>flag[i][j]){
			minV =flag[i][j];
		}
	}
	return minV;
}

int main(int argc, char* argv[])
{
	int n;
	cin>>n;
	string S;

	int i,j;
	for (i=0;i<50;i++){
		for (j=0;j<26;j++){
			flag[i][j]=0;
		}
	}
	int minSLen=50;
	for (i=0;i<n;i++){
		cin>>S;
		size_t sLen=S.length();
		if (minSLen>sLen){
			minSLen=(int)sLen;
		}
		for (j=0;j<sLen;j++){
			flag[i][S[j]-'a']++;
		}
	}
	int MinJ[26];
	minSLen=26;
	for (j=0;j<minSLen;j++){
		MinJ[j] = getMin(j,n);
		for (i=0;i<n;i++){
			flag[i][j]=MinJ[j];
		}
	}
	bool match=false;
	for (j=0;j<minSLen;j++){
		if (MinJ[j]>0){
			for (i=0;i<MinJ[j];i++){
				cout<<char('a'+j);
			}
			match=true;
		}
	}
	if (!match){
		cout<<"";
	}
	cout<<endl;
	return 0;
}