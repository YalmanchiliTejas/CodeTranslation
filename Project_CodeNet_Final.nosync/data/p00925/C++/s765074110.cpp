#include<cstdio>
#include<vector>
using namespace std;
int main(){
	char s[200];
	int n,a,b,c,i;
	vector<int> v;
	scanf("%s",s);
	scanf("%d",&c);
	a=s[0]-'0';
	for(i=2;s[i-1];i+=2){
		if(s[i-1]=='+') a+=(s[i]-'0');
		else a*=(s[i]-'0');
	}
	v.push_back(s[0]-'0');
	for(i=2;s[i-1];i+=2){
		if(s[i-1]=='+') v.push_back(s[i]-'0');
		else v.back()*=(s[i]-'0');
	}
	b=0;
	for(i=0;i<v.size();i++) b+=v[i];
	if(a==c&&b==c) printf("U\n");
	else if(a==c&&b!=c) printf("L\n");
	else if(a!=c&&b==c) printf("M\n");
	else printf("I\n");
	return 0;
}