# include<iostream>
# include<queue>
# include<stack>
# include<algorithm>
# include<cmath> 
# include<cstring>
# include<map>
# include<iomanip>
using namespace std;
const int INF =pow(10,9)+7;
int a[1000000];

struct P{
	int x,y;
};
bool cmp(P a,P b)
{
	 return 1;
}

void update(int a,int b,int k,int l,int r)
{
	 
}
double sum(int i)
{
	 double s=1.0*(i+1)/2;
	 return s;
}
int cal(string s)
{
	 int l =s.length();
	 return s[0]-'0'+(l-1)*9;
}
int cal1(string s)
{
	int l =s.length();
	int sum =0;
	for(int i=1;i<l;i++)
	{
		 if(s[i]-'0'>0)
		 {
		 	  sum+=s[i]-'0';
		 	  for(int j=i+1;j<l;j++)
		 	  sum+=9;
		 	  break;
		 }
	}
	return (l-1)*(l-2)*9*9/2+(s[0]-'0'-1)*9*(l-1)+sum;
}

int cal4(int N)
{
	 int s=0;
	 for(int i=1;i<=N;i++)
	 {
	 	s+=i*(i+1)/2;
	  } 
	  
	  return s;
} 

int cal3(string s)
{
	 int l = s.length();
	 string s1 = "";
	 for(int i=1;i<l;i++)
	 {
	 	 if(s[i]!='0')
	 	 {
	 	 	for(int j=i;j<l;j++)
	 	 	s1+=s[j];
	 	 	break;
		  }
		 else if(i==l-1)
		 {
		 	s1+=s[i];
		  } 
	 }
	 
	
	 
	 
	return 9*9*9*cal4(l-3)+(s[0]-'0'-1)*9*9*(l-1)*(l-2)/2+cal1(s1);
}

int main ()
{
	 int t=1;
	 //cin>>t;
	 while(t>0)
	 {
	 	  t--;
	      string N;
		  cin>>N;
		  int K;
		  cin>>K; 
		  if(K==1)
		  cout<<cal(N)<<endl;
		  else if(K==2)
		  cout<<cal1(N)<<endl;  
		  else
		  cout<<cal3(N)<<endl;
	 }
    	
	return 0;
}