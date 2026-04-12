#include<iostream>
using namespace std;
int main(){
	int n;
	char s[51][51];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	char ans[51];
	int point=0;
	int tmp=0;
	for(char i='a';i!='{';){
		for(int j=0;j<n;j++){
			for(int k=0;s[j][k]!='\0';k++){
				if(s[j][k]==i){
					s[j][k]='1';
					tmp=1;
					break;
				}
			}
			if(tmp==1){
				tmp=0;
			}
			else{
				break;
			}
			if(j==n-1){
				tmp=1;
			}
		}
		if(tmp==1){
			ans[point]=i;
			point++;
		}
		else{
			i++;
		}
		tmp=0;
	}
	if(point==0){
		return 0;
	}
	for(int i=0;i<point;i++){
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}