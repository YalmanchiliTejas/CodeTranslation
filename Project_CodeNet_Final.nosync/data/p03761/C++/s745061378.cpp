#include<bits/stdc++.h>
using namespace std;


#define f(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define char_f(i,a) for(int i=(int)(a);(char)s[i]!='\0';i++)
#define rf(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define llf(i,a,b) for(long long int i=(long long int)(a);i<=(long long int)(b);i++)
#define llrf(i,a,b) for(long long int i=(long long int)(a);i>=(long long int)(b);i--)



#define ll long long
#define fi first
#define se second
#define pb push_back
#define pop pop_back
#define mem(ara) memset((ara),0,sizeof(ara))
#define memn(ara) memset((ara),-1,sizeof(ara))
#define b begin()
#define e end()
#define em emplace
#define eb emplace_back





#define si set<int>
#define sd set<double>
#define sll set<long long int>
#define ss set<string>
#define sc set<char>

#define pii pair<int,int>
#define pli pair<long long int,int>
#define pil pair<int,long long int>
#define pll pair<long long int,long long int>
#define pci pair<char,int>
#define pic pair<int,char>
#define pcl pair<char,long long int>
#define plc pair<long long int,char>

#define pss pair<string,string>
#define pcc pair<char,char>

#define pis pair<int,string>
#define psi pair<string,int>
#define pls pair<long long int,string>
#define psl pair<string,long long int>
#define pdd pair<double,double>
#define pcs pair<char,string>
#define psc pair<string,char>



#define vi  vector<int>
#define vll vector<long long int>
#define vd vector<double>
#define vs vector<string>
#define vc vector<char>
#define vii vector<pii>



#define mod 1000000007
#define mx (1<<30)-1
#define llmx (1ll<<62)
#define n_size 100005
#define g_size 10000005
double PI=acos(-1);



///unsigned int uMAX=4294967295;
///unsigned ll int ullMAX=18446744073709551615;





int arr[g_size],arr1[g_size];



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n,m,T,res;

	int maxi=-mx,mini=mx,count=0;

	int i,j,k;

	bool flag;

	string s1,s2;

	char s[100000];

	int ara[n_size],ara2[n_size];

    f(i,0,27){
        arr1[i]=mx;
    }

	cin>>n;
	f(i,0,n-1)
	{
	    cin>>s;
	    mem(arr);
	    f(j,0,strlen(s)-1)
	    {
	        arr[s[j]-'a']++;
	    }

	    f(i,0,27){
            arr1[i]=min(arr1[i],arr[i]);
	    }

	}

	f(i,0,27)
	{
	   if(arr1[i]>=0 && arr1[i]<=50) {
        k=arr1[i];
        f(j,1,k)
	    {
	        char c=i+'a';
	        cout<<c;
	    }
	}
	}
	cout<<endl;


}
