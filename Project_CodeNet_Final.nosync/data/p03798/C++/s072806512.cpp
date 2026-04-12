#include <bits/stdc++.h>
using namespace std;
string x;
string ans;
int main(void)
{
    int n;
    cin>>n;
    cin>>x;
    ans.clear();
    ans.resize(n);
    bool flag=false;

    if(x[0]=='o')
    {
        ans[0]='S';
        ans[1]='S';
        ans[n-1]='S';
        for(int i=1;i<n-1;i++)
        {
            if(ans[i]=='S'&&x[i]=='o')
            {
                ans[i+1]=ans[i-1];
            }
            else if(ans[i]=='S'&&x[i]=='x')
            {
                if(ans[i-1]=='S')
                {
                    ans[i+1]='W';
                }
                if(ans[i-1]=='W')
                {
                    ans[i+1]='S';
                }
            }
            else if(ans[i]=='W'&&x[i]=='x')
            {
                ans[i+1]=ans[i-1];
            }
            else if(ans[i]=='W'&&x[i]=='o')
            {
                if(ans[i-1]=='S')
                {
                    ans[i+1]='W';
                }
                if(ans[i-1]=='W')
                {
                    ans[i+1]='S';
                }
            }
        }
        if(ans[n-1]!='S')
        {
            flag=false;
        }
        else
        {
            if(x[n-1]=='o')
            {
                if(ans[n-2]=='S')
                {
                    flag=true;
                }
            }
            else
            {
                if(ans[n-2]=='W')
                {
                    flag=true;
                }
            }
        }
        if(flag)
        {
            cout <<ans<<endl;
            return 0;
        }
        ans.clear();
        ans.resize(n);



        ans[0]='S';
        ans[1]='W';
        ans[n-1]='W';
        for(int i=1;i<n-1;i++)
        {
            if(ans[i]=='S'&&x[i]=='o')
            {
                ans[i+1]=ans[i-1];
            }
            else if(ans[i]=='S'&&x[i]=='x')
            {
                if(ans[i-1]=='S')
                {
                    ans[i+1]='W';
                }
                if(ans[i-1]=='W')
                {
                    ans[i+1]='S';
                }
            }
            else if(ans[i]=='W'&&x[i]=='x')
            {
                ans[i+1]=ans[i-1];
            }
            else if(ans[i]=='W'&&x[i]=='o')
            {
                if(ans[i-1]=='S')
                {
                    ans[i+1]='W';
                }
                if(ans[i-1]=='W')
                {
                    ans[i+1]='S';
                }
            }
        }
        if(ans[n-1]!='W')
        {
            flag=false;
        }
        else
        {
            if(x[n-1]=='o')
            {
                if(ans[n-2]=='W')
                {
                    flag=true;
                }
            }
            else
            {
                if(ans[n-2]=='S')
                {
                    flag=true;
                }
            }
        }
        if(flag)
        {
            cout <<ans<<endl;
            return 0;
        }
        ans.clear();
        ans.resize(n);


        ans[0]='W';
        ans[1]='S';
        ans[n-1]='W';
        for(int i=1;i<n-1;i++)
        {
            if(ans[i]=='S'&&x[i]=='o')
            {
                ans[i+1]=ans[i-1];
            }
            else if(ans[i]=='S'&&x[i]=='x')
            {
                if(ans[i-1]=='S')
                {
                    ans[i+1]='W';
                }
                if(ans[i-1]=='W')
                {
                    ans[i+1]='S';
                }
            }
            else if(ans[i]=='W'&&x[i]=='x')
            {
                ans[i+1]=ans[i-1];
            }
            else if(ans[i]=='W'&&x[i]=='o')
            {
                if(ans[i-1]=='S')
                {
                    ans[i+1]='W';
                }
                if(ans[i-1]=='W')
                {
                    ans[i+1]='S';
                }
            }
        }
        if(ans[n-1]!='W')
        {
            flag=false;
        }
        else
        {
            if(x[n-1]=='o')
            {
                if(ans[n-2]=='S')
                {
                    flag=true;
                }
            }
            else
            {
                if(ans[n-2]=='W')
                {
                    flag=true;
                }
            }
        }
        if(flag)
        {
            cout <<ans<<endl;
            return 0;
        }
        ans.clear();
        ans.resize(n);


         ans[0]='W';
        ans[1]='W';
        ans[n-1]='S';
        for(int i=1;i<n-1;i++)
        {
            if(ans[i]=='S'&&x[i]=='o')
            {
                ans[i+1]=ans[i-1];
            }
            else if(ans[i]=='S'&&x[i]=='x')
            {
                if(ans[i-1]=='S')
                {
                    ans[i+1]='W';
                }
                if(ans[i-1]=='W')
                {
                    ans[i+1]='S';
                }
            }
            else if(ans[i]=='W'&&x[i]=='x')
            {
                ans[i+1]=ans[i-1];
            }
            else if(ans[i]=='W'&&x[i]=='o')
            {
                if(ans[i-1]=='S')
                {
                    ans[i+1]='W';
                }
                if(ans[i-1]=='W')
                {
                    ans[i+1]='S';
                }
            }
        }
        if(ans[n-1]!='S')
        {
            flag=false;
        }
        else
        {
            if(x[n-1]=='o')
            {
                if(ans[n-2]=='W')
                {
                    flag=true;
                }
            }
            else
            {
                if(ans[n-2]=='S')
                {
                    flag=true;
                }
            }
        }
        if(flag)
        {
            cout <<ans<<endl;
            return 0;
        }
        ans.clear();
        ans.resize(n);
    }
    else
    {
        ans.resize(n);
        ans[0]='S';
        ans[1]='S';
        ans[n-1]='W';
        for(int i=1;i<n-1;i++)
        {
            if(ans[i]=='S'&&x[i]=='o')
            {
                ans[i+1]=ans[i-1];
            }
            else if(ans[i]=='S'&&x[i]=='x')
            {
                if(ans[i-1]=='S')
                {
                    ans[i+1]='W';
                }
                if(ans[i-1]=='W')
                {
                    ans[i+1]='S';
                }
            }
            else if(ans[i]=='W'&&x[i]=='x')
            {
                ans[i+1]=ans[i-1];
            }
            else if(ans[i]=='W'&&x[i]=='o')
            {
                if(ans[i-1]=='S')
                {
                    ans[i+1]='W';
                }
                if(ans[i-1]=='W')
                {
                    ans[i+1]='S';
                }
            }
        }
        if(ans[n-1]!='W')
        {
            flag=false;
        }
        else
        {
            if(x[n-1]=='o')
            {
                if(ans[n-2]=='W')
                {
                    flag=true;
                }
            }
            else
            {
                if(ans[n-2]=='S')
                {
                    flag=true;
                }
            }
        }
        if(flag)
        {
            cout <<ans<<endl;
            return 0;
        }
        ans.clear();
        ans.resize(n);



        ans[0]='S';
        ans[1]='W';
        ans[n-1]='S';
        for(int i=1;i<n-1;i++)
        {
             if(ans[i]=='S'&&x[i]=='o')
            {
                ans[i+1]=ans[i-1];
            }
            else if(ans[i]=='S'&&x[i]=='x')
            {
                if(ans[i-1]=='S')
                {
                    ans[i+1]='W';
                }
                if(ans[i-1]=='W')
                {
                    ans[i+1]='S';
                }
            }
            else if(ans[i]=='W'&&x[i]=='x')
            {
                ans[i+1]=ans[i-1];
            }
            else if(ans[i]=='W'&&x[i]=='o')
            {
                if(ans[i-1]=='S')
                {
                    ans[i+1]='W';
                }
                if(ans[i-1]=='W')
                {
                    ans[i+1]='S';
                }
            }
        }
        if(ans[n-1]!='S')
        {
            flag=false;
        }
        else
        {
            if(x[n-1]=='o')
            {
                if(ans[n-2]=='S')
                {
                    flag=true;
                }
            }
            else
            {
                if(ans[n-2]=='W')
                {
                    flag=true;
                }
            }
        }
        if(flag)
        {
            cout <<ans<<endl;
            return 0;
        }
        ans.clear();
        ans.resize(n);
        ans[0]='W';
        ans[1]='S';
        ans[n-1]='S';
        for(int i=1;i<n-1;i++)
        {
             if(ans[i]=='S'&&x[i]=='o')
            {
                ans[i+1]=ans[i-1];
            }
            else if(ans[i]=='S'&&x[i]=='x')
            {
                if(ans[i-1]=='S')
                {
                    ans[i+1]='W';
                }
                if(ans[i-1]=='W')
                {
                    ans[i+1]='S';
                }
            }
            else if(ans[i]=='W'&&x[i]=='x')
            {
                ans[i+1]=ans[i-1];
            }
            else if(ans[i]=='W'&&x[i]=='o')
            {
                if(ans[i-1]=='S')
                {
                    ans[i+1]='W';
                }
                if(ans[i-1]=='W')
                {
                    ans[i+1]='S';
                }
            }
        }
         if(ans[n-1]!='S')
        {
            flag=false;
        }
        else
        {
            if(x[n-1]=='o')
            {
                if(ans[n-2]=='W')
                {
                    flag=true;
                }
            }
            else
            {
                if(ans[n-2]=='S')
                {
                    flag=true;
                }
            }
        }
        if(flag)
        {
            cout <<ans<<endl;
            return 0;
        }
        ans.clear();
        ans.resize(n);


         ans[0]='W';
        ans[1]='W';
        ans[n-1]='W';
        for(int i=1;i<n-1;i++)
        {
            if(ans[i]=='S'&&x[i]=='o')
            {
                ans[i+1]=ans[i-1];
            }
            else if(ans[i]=='S'&&x[i]=='x')
            {
                if(ans[i-1]=='S')
                {
                    ans[i+1]='W';
                }
                if(ans[i-1]=='W')
                {
                    ans[i+1]='S';
                }
            }
            else if(ans[i]=='W'&&x[i]=='x')
            {
                ans[i+1]=ans[i-1];
            }
            else if(ans[i]=='W'&&x[i]=='o')
            {
                if(ans[i-1]=='S')
                {
                    ans[i+1]='W';
                }
                if(ans[i-1]=='W')
                {
                    ans[i+1]='S';
                }
            }
        }
        if(ans[n-1]!='W')
        {
            flag=false;
        }
        else
        {
            if(x[n-1]=='o')
            {
                if(ans[n-2]=='S')
                {
                    flag=true;
                }
            }
            else
            {
                if(ans[n-2]=='W')
                {
                    flag=true;
                }
            }
        }
        if(flag)
        {
            cout <<ans<<endl;
            return 0;
        }
        ans.clear();
        ans.resize(n);
    }
    cout <<"-1"<<endl;
    return 0;
}
