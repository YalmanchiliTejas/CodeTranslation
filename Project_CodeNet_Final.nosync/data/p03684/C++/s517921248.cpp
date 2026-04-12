#include<bits/stdc++.h>
using namespace std;
#define con continue
#define bk break
#define LL long long
#define db double
#define pt cout<<'\n'
#define ms(a, b) memset((a), (b), sizeof(a))
#define mp make_pair
#define endl '\n'
int inf=2147483647;const long long ll =9223372036854775807,ninf=1000000000;const double eps = 1e-6; const long long nll =223372036854775807;
#define sz size()
#define len(X) strlen(X)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ULL unsigned long long
#define de cout<<"test"<<endl;
#define st system("pause");
#define M_PI 3.1415926
struct data {
int x,y,z;
};
data A[100005]={};
int fa[100005]={};
int find(int now){
	if(fa[now]!=now)fa[now]=find(fa[now]);
	return fa[now];
}

bool cmp1(data a,data b){
return a.x<b.x;
}
bool cmp2(data a,data b){
return a.y<b.y;
}
int main()
{
 int a;
 while(cin>>a){
        for(int i=0;i<=a;i++){
            fa[i]=i;
        }
        vector<data>ans;
    for(int i=0;i<a;i++){
        cin>>A[i].x>>A[i].y;
        A[i].z=i+1;
    }
    sort(A,A+a,cmp1);
    for(int i=0;i<a-1;i++){
        data tmp;
        tmp.x=A[i+1].x-A[i].x,tmp.y=A[i].z,tmp.z=A[i+1].z;
        ans.push_back(tmp);
    }
    sort(A,A+a,cmp2);
      for(int i=0;i<a-1;i++){
        data tmp;
        tmp.x=A[i+1].y-A[i].y,tmp.y=A[i].z,tmp.z=A[i+1].z;
        ans.push_back(tmp);
    }
    sort(ans.begin(),ans.end(),cmp1);
    int sum=0;
    for(int i=0;i<ans.sz;i++){
        int l=ans[i].y,r=ans[i].z;
        int t1=find(l),t2=find(r);
        if( t1!=t2 ){
            fa[t1]=t2;
            sum+=ans[i].x;
        }
    }
    cout<<sum<<endl;
 }

    return 0;
}
