#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a=1;
int main(void){
        for(;;){

        int n,q=0;

        cin>>n;
        if(n==0){
            //cout<<endl;
            break;
        }
        if(a==1);
        else cout<<endl;
        int w[20],l[20],d[20];
        int p[20];

        char team[20][40];


        for(int i=0;i<n;i++){
            scanf("%s%d%d%d",team[i],&w[i],&l[i],&d[i]);
            p[i]=w[i]*3+d[i];
        }
        for(int i=3*n;i>=0;i--){
            for(int j=0;j<n;j++){
                if(p[j]==i){
                    cout<<team[j]<<","<<p[j]<<endl;
                    q++,a++;
                }
            }

        }


        }
	return 0;
}