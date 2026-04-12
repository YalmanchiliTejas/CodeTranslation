    #include<bits/stdc++.h>  
    using namespace std;  
    const int maxn=1e5+10;  
    int n,ans[maxn];  
    char ch[maxn];  
    bool check()  
    {  
        if (!ans[n])  
        {  
            if (ch[n]=='o'&&ans[n-1]!=ans[1]) return 0;  
            if (ch[n]=='x'&&ans[n-1]==ans[1]) return 0;  
        }  
        else  
        {  
            if (ch[n]=='x'&&ans[n-1]!=ans[1]) return 0;  
            if (ch[n]=='o'&&ans[n-1]==ans[1]) return 0;  
        }  
        if (!ans[1])  
        {  
            if (ch[1]=='o'&&ans[n]!=ans[2]) return 0;  
            if (ch[1]=='x'&&ans[n]==ans[2]) return 0;  
        }  
        else  
        {  
            if (ch[1]=='x'&&ans[n]!=ans[2]) return 0;  
            if (ch[1]=='o'&&ans[n]==ans[2]) return 0;  
        }  
        return 1;  
    }  
    int main()  
    {  
        scanf("%d%s",&n,ch+1);  
        for (int S=0;S<4;S++)  
        {  
            ans[1]=S&1;  
            ans[2]=(S>>1)&1;  
            for (int i=3;i<=n;i++)  
                if (!ans[i-1])  
                {  
                    if (ch[i-1]=='o') ans[i]=ans[i-2];  
                    else ans[i]=ans[i-2]^1;  
                }  
                else  
                {  
                    if (ch[i-1]=='x') ans[i]=ans[i-2];  
                    else ans[i]=ans[i-2]^1;  
                }  
            if (check())  
            {  
                for (int i=1;i<=n;i++)  
                    if (!ans[i]) printf("S");  
                    else printf("W");  
                return 0;  
            }  
        }  
        cout<<"-1";  
        return 0;  
    }  