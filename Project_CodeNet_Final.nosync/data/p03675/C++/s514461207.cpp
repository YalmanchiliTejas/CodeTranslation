#include<bits/stdc++.h>
#define ll long long
#define MAX_N 200005
using namespace std;

int main()
{
	//freopen("t.txt","r",stdin);
	int n;
	scanf("%d",&n);
    ll a[MAX_N],b[MAX_N];
	for (int i=1;i<=n;i++){
	scanf("%d",&a[i]);
	}
    int j=1; bool check =true;
    for (int i=n;i>=1;i--){
        if (check==true){
           b[j]=a[i];
           check= false;
        }
        else{
            b[n-j+1]= a[i];
            check = true;
            j++;
        }
    }
    for (int i=1;i<=n;i++) cout<<b[i]<<" ";
}
