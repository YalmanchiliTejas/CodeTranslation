    #include<iostream>
    #include<cstdio>
    #include<cmath>
    #include<cstring>
    #include<string>
     
    typedef long long ll;
    int N,a,b,ans;
    int main(){
        scanf("%d",&N);
        a=(N/15)*200;
        b=N*800;
        ans=b-a;
        printf("%d",ans );
        return 0;
    }