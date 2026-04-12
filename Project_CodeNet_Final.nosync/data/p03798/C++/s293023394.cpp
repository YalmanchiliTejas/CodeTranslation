/*
//shurenT4 zoo
//WA——9/16 朴素到WA
//（“稻花香里说丰年，听取WA声一片”） 
#pragma GCC optimize("Ofast",3,"inline")
#include <bits/stdc++.h>
using namespace std;
int a[100000],len;
char ans[2]={'S','W'};
string s; 
bool turn(){
	for(int i=2;i<len-1;i++){
		if(s[i]=='o') a[i+1]=(a[i]+a[i-1])%2;
		else a[i+1]=!((a[i]+a[i-1])%2);
	}
	if(s[len-1]=='o')return(a[0]==(a[len-1]+a[len-2])%2);
	else return(a[0]!=(a[len-1]+a[len-2])%2);
}
void output(){
	for(int i=0;i<len;i++) cout<<ans[a[i]];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin>>len>>s;
	for(int i=0;i<4;i++){
		if(i==0){
			a[0]=0;a[1]=0;
			if(s[0]=='o')a[len-1]=0;
			else a[len-1]=1;
			if(s[1]=='o')a[2]=0;
			else a[2]=1;
			if(turn()){
				output();
				return 0;	
			}
		}
		if(i==1){
			a[0]=0;a[1]=1;
			if(s[0]=='o')a[len-1]=1;
			else a[len-1]=0;
			if(s[1]=='o')a[2]=1;
			else a[2]=0;
			if(turn()){
				output();
				return 0;	
			}
		}
		if(i==2){
			a[0]=1;a[1]=0;
			if(s[0]=='o')a[len-1]=1;
			else a[len-1]=0;
			if(s[1]=='o')a[2]=1;
			else a[2]=0;
			if(turn()){
				output();
				return 0;	
			}
		}
		if(i==3){
			a[0]=1;a[1]=1;
			if(s[0]=='o')a[len-1]=0;
			else a[len-1]=1;
			if(s[1]=='o')a[2]=0;
			else a[2]=1;
			if(turn()){
				output();
				return 0;	
			}
		}
	}
	cout<<"-1";
	return 0;
}
*/
/*
//AC——朴素写法 
#pragma GCC optimize("Ofast",3,"inline")
#include <bits/stdc++.h>
using namespace std;
const int M=1e6;
int a[M];
int main(){
	int n;
	string s;
	cin>>n>>s;
	s+=s;
	for(int i1=0;i1<2;i1++){
		for(int i2=0;i2<2;i2++){
			a[0]=i1;a[1]=i2;
			for(int i=2;i<=n+1;i++){
				if(s[i-1]=='o'&&a[i-1]==0) a[i]=1-a[i-2];
				if(s[i-1]=='o'&&a[i-1]==1) a[i]=a[i-2];
				if(s[i-1]=='x'&&a[i-1]==0) a[i]=a[i-2];
				if(s[i-1]=='x'&&a[i-1]==1) a[i]=1-a[i-2];
			}
			if(a[n]==a[0]&&a[n+1]==a[1]){
				for(int i=0;i<n;i++){
					cout<<(a[i]?'S':'W');
				}
				return 0;
			}
		}
	}
	cout<<-1<<endl;
	return 0;
} 
*/
/*
//AC——朴素写法 2 
#include<bits/stdc++.h>
#define N 100009
using namespace std;
const int INF = 0x3f3f3f3f;
char s[N];
int ans[N];
int nx[4] = {1, 1, 0, 0};
int ny[4] = {1, 0, 0, 1};
bool check(int a, int b, int n)
{
    ans[0] = a; ans[1] = b;
    for(int i = 1; i < n - 1; i++)
    {
        if(s[i] == 'o')
        {
            if(ans[i]) ans[i + 1] = ans[i - 1];
            else ans[i + 1] = !ans[i - 1];
        }
        else
        {
            if(ans[i]) ans[i + 1] = !ans[i - 1];
            else ans[i + 1] = ans[i - 1];
        }
    }
    if(s[0] == 'o')
    {
        if(ans[0])
        {
            if(ans[1] != ans[n - 1]) return false;
        }
        else if(ans[1] == ans[n - 1]) return false;
    }
    else
    {
        if(ans[0])
        {
            if(ans[1] == ans[n - 1]) return false;
        }
        else if(ans[1] != ans[n - 1]) return false;
    }
    if(s[n - 1] == 'o')
    {
        if(ans[n - 1])
        {
            if(ans[0] != ans[n - 2]) return false;
        }
        else if(ans[0] == ans[n - 2]) return false;
    }
    else
    {
        if(ans[n - 1])
        {
            if(ans[0] == ans[n - 2]) return false;
        }
        else if(ans[0] != ans[n - 2]) return false;
    }
    return true;
}
int main()
{
    int n;
    scanf("%d %s", &n, s);
    for(int i = 0; i < 4; i++)
    {
        if(check(nx[i], ny[i], n))
        {
            for(int i = 0; i < n; i++)
            {
                if(ans[i]) printf("S");
                else printf("W");
            }
            printf("\n");
            exit(0);
        }
    }
    puts("-1");
    return 0;
}
*/
//AC——秀操作
#pragma GCC optimize("Ofast",3,"inline")
#include <bits/stdc++.h>
using namespace std;
char s[100005];
bool t[100005];
int main()
{
	int n;
	cin>>n>>s;
	s[0];
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			t[0]=i;
			t[1]=j;
			for(int k=1;k<n-1;k++)
				t[k+1]=t[k-1]^t[k]^(s[k]=='x');
			if((s[n-1]=='x')==t[n-2]^t[n-1]^t[0]&&(s[0]=='x')==t[n-1]^t[0]^t[1])
			{
				for(int k=0;k<n;k++)
				{
					if(t[k])
						cout<<'W';
					else
						cout<<'S';
				}
				return 0;
			}
		}
	}
	cout<<"-1";

	return 0;
}
