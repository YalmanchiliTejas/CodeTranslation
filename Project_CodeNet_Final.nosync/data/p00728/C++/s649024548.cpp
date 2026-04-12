#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
        int n;
        int s[117];
        int chk;
        while(1){
                scanf("%d",&n);
                if(!n)
                        break;
                for(int i=0;i<n;i++){
                        scanf("%d",&s[i]);
                }
                sort(s,s+n);
            chk=0;
                for(int j=1;j<n-1;j++)
                        chk+=s[j];
                printf("%d\n",chk/(n-2));
        }
        return 0;
}