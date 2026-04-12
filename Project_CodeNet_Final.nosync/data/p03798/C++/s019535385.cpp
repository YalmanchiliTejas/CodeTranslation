    #include <bits/stdc++.h>

    using namespace std;
    int n;
    const int maxn=1e7+5;
    int ans[maxn];
    char s[maxn];
    int main()
    {
        cin>>n;
        getchar();
        int f=0;
        int mark;
        scanf("%s",s+1);
        for(int k=0;k<=1;k++){
            for(int l=0;l<=1;l++){
                ans[1]=l;
                ans[2]=k;

        for(int i=3;i<=n;i++){
            if(ans[i-1]==0){
                if(s[i-1]=='o'){
                    ans[i]=ans[i-2];
                }
                else{
                    ans[i]=1-ans[i-2];
                }
            }
            else{
                if(s[i-1]=='o'){
                    ans[i]=1-ans[i-2];
                }
                else{
                   ans[i]=ans[i-2];
                }

            }
        }
        if(ans[n]==0){
            if(s[n]=='o'){
                if(ans[n-1]!=ans[1]){
                    continue;
                }
            }
            else{
                if(s[n]=='x'){
                    if(ans[n-1]==ans[1]){
                        continue;
                    }
                }
            }
        }
        else{
            if(s[n]=='o'){
                if(ans[n-1]==ans[1]){
                    continue;
                }
            }
            else{
                if(s[n]=='x'){
                    if(ans[n-1]!=ans[1]){
                        continue;
                    }
                }
            }
        }
        if(ans[1]==0){
            if(s[1]=='o'){
                if(ans[2]!=ans[n]){
                    continue;
                }
            }
            else{
                if(ans[2]==ans[n]){
                    continue;
                }
            }
        }
        else{
            if(s[1]=='o'){
                if(ans[2]==ans[n]){
                    continue;
                }
            }
            else{
                if(ans[2]!=ans[n]){
                    continue;
                }
            }
        }
        f=1;
        goto solve;







        }
        }
        solve:

        if(f){
            for(int i=1;i<=n;i++){
                if(ans[i]==0){
                    printf("S");
                }
                else{
                    printf("W");
                }
            }
        }
        else{
            printf("-1");
        }
        cout<<endl;

        return 0;
    }
