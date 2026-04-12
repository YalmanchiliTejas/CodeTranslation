#include<bits/stdc++.h>
using namespace std;
struct poi{
    int x;
    int y;
    int num1;
    int num2;
}a[100005];
poi b[100005];
int fa[100005];
bool cmp1(poi q,poi w){
    return q.x<w.x;
}
bool cmp2(poi q,poi w){
    return q.y<w.y;
}
int Find(int x)
{
	int r=x;
	while(r!=fa[r])
		r=fa[r];

	int i=x,j;

	while(fa[i]!=r)
	{
		j=fa[i];
		fa[i]=r;
		i=j;
	}

	return r;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
        a[i].num1=i;
        b[i]=a[i];
    }
    sort(a,a+n,cmp1);
    sort(b,b+n,cmp2);
    for(int i=0;i<n-1;i++)
    {
        a[i].x=a[i+1].x-a[i].x;
        a[i].num2=a[i+1].num1;
    }
    for(int i=0;i<n-1;i++)
    {
        b[i].y=b[i+1].y-b[i].y;
        b[i].num2=b[i+1].num1;
    }
    sort(a,a+n-1,cmp1);
    sort(b,b+n-1,cmp2);

    for(int i=0;i<n;i++) fa[i]=i;
    int s1=0;
    int s2=0;
    long long ans=0;

    while(s1<n-1&&s2<n-1){
        int temp1=a[s1].x;
        int temp2=b[s2].y;
        if(temp1<temp2){
            int fa1=Find(a[s1].num1);
            int fa2=Find(a[s1].num2);
            if(fa1!=fa2){
                fa[fa1]=fa2;
                ans+=temp1;
            }
            s1++;
        }
        else{
            int fa1=Find(b[s2].num1);
            int fa2=Find(b[s2].num2);
            if(fa1!=fa2){
                fa[fa1]=fa2;
                ans+=temp2;
            }
            s2++;
        }
        //printf("%d %d %lld\n",temp1,temp2,ans);

    }
    printf("%lld\n",ans);

}
