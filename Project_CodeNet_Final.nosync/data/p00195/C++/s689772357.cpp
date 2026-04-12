#include<iostream>
using namespace std;

int main(){
	int shop[5];
	char ans;int answer;
	int s1,s2;
	
	while(cin>>s1>>s2){
	
		if(s1==0&&s2==0)break;
		shop[0]=s1+s2;
		
	for(int i=1;i<5;i++){
		cin>>s1>>s2;
		shop[i]=s1+s2;
	}
	answer=0;
	for(int i=0;i<5;i++){
	answer=max(shop[i],answer);
	}
	if(answer==shop[0])ans='A';
	if(answer==shop[1])ans='B';
	if(answer==shop[2])ans='C';
	if(answer==shop[3])ans='D';
	if(answer==shop[4])ans='E';
	
	cout<<ans<<" "<<answer<<endl;
}
	return 0;
	
}