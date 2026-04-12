#include <iostream>
using namespace std;


int main(){
    const int MX=2e5+9;
    int n=10, a[MX];
    string s;
    scanf("%d", &n);
    cin>>s;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            a[1]=i;
            a[2]=j;
            if(s[0]=='o'&&a[1]==0)a[0]=a[2];
            if(s[0]=='o'&&a[1]==1)a[0]=a[2]^1;
            if(s[0]=='x'&&a[1]==0)a[0]=a[2]^1;
            if(s[0]=='x'&&a[1]==1)a[0]=a[2];
            for(int k=3; k<=n+1; k++){
                if(s[k-2]=='o'&&a[k-1]==0)a[k]=a[k-2];
                if(s[k-2]=='o'&&a[k-1]==1)a[k]=a[k-2]^1;
                if(s[k-2]=='x'&&a[k-1]==0)a[k]=a[k-2]^1;
                if(s[k-2]=='x'&&a[k-1]==1)a[k]=a[k-2];
         
            }
            if(a[n+1]==a[1]&&a[0]==a[n]){
                for(int k=1; k<n+1; k++){
                    if(a[k])printf("W");
                        else printf("S");
                }
                printf("\n");
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;
}
