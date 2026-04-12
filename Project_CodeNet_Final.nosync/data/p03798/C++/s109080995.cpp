#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iomanip>
#include <cstdio>
#include <float.h>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <stack>
#include <functional>
       
using namespace std;
       
#define endl '\n'
#define MOD 1000000007
#define INF 1ll<<30
 
// #define MAX 100010
 
#define eps 1e-11
#define bit_max 1ll<<32
#define _USE_MATH_DEFINES


int a1[100005]={0},a2[100005]={0},a3[100005]={0},a4[100005]={0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
        // freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    // #endif
    int n;
    cin>>n;
    string a;
    cin>>a;
    
    a1[0]=1;
    a2[0]=1;
    a3[0]=2;
    a4[0]=2;
    a1[1]=1;
    a2[1]=2;
    a3[1]=1;
    a4[1]=2;
    int patt=-1;
    for(int i=0;i<n;i++)
    {
        if(a1[i]==1)
        {
            if(a[i]=='o')
            {
                if(a1[(i-1+n)%n]==0&&a1[(i+1)%n]!=0)
                {
                    a1[(i-1+n)%n]=a1[(i+1)%n];
                }
                if(a1[(i+1)%n]==0&&a1[(i-1+n)%n]!=0)
                {
                    a1[(i+1)%n]=a1[(i-1+n)%n];
                }
                if(a1[(i-1+n)%n]!=a1[(i+1)%n])
                {
                    patt=0;
                    break;
                }
            }
            else
            {
                if(a1[(i+1)%n]==0&&a1[(i-1+n)%n]!=0)
                {
                    if(a1[(i-1+n)%n]==1)
                        a1[(i+1)%n]=2;
                    else
                        a1[(i+1)%n]=1;
                }
                if(a1[(i-1+n)%n]==0&&a1[(i+1)%n]!=0)
                {
                    if(a1[(i+1)%n]==1)
                        a1[(i-1+n)%n]=2;
                    else
                        a1[(i-1+n)%n]=1;
                }
                if(a1[(i-1+n)%n]==a1[(i+1)%n])
                {
                    patt=0;
                    break;
                }
            }   
        }
        else if(a1[i]==2)
        {
            if(a[i]!='o')
            {
                if(a1[(i-1+n)%n]==0&&a1[(i+1)%n]!=0)
                {
                    a1[(i-1+n)%n]=a1[(i+1)%n];
                }
                if(a1[(i+1)%n]==0&&a1[(i-1+n)%n]!=0)
                {
                    a1[(i+1)%n]=a1[(i-1+n)%n];
                }
                if(a1[(i-1+n)%n]!=a1[(i+1)%n])
                {
                    patt=0;
                    break;
                }
            }
            else
            {
                if(a1[(i+1)%n]==0&&a1[(i-1+n)%n]!=0)
                {
                    if(a1[(i-1+n)%n]==1)
                        a1[(i+1)%n]=2;
                    else
                        a1[(i+1)%n]=1;
                }
                if(a1[(i-1+n)%n]==0&&a1[(i+1)%n]!=0)
                {
                    if(a1[(i+1)%n]==1)
                        a1[(i-1+n)%n]=2;
                    else
                        a1[(i-1+n)%n]=1;
                }
                if(a1[(i-1+n)%n]==a1[(i+1)%n])
                {
                    patt=0;
                    break;
                }
            }
        }
    }
    if(patt==-1)
    {
        int cr=0;
        for(int i=0;i<n;i++)
        {
            if(a1[i]!=0)
                cr++;
        }
        if(cr==n)
        {   
            for(int i=0;i<n;i++)
            {
                if(a1[i]==1)
                    cout<<"S";
                else
                    cout<<"W";
            }
            cout<<endl;
            return 0;
        }
       
    }
    patt=-1;
    for(int i=0;i<n;i++)
    {
        if(a2[i]==1)
        {
            if(a[i]=='o')
            {
                if(a2[(i-1+n)%n]==0&&a2[(i+1)%n]!=0)
                {
                    a2[(i-1+n)%n]=a2[(i+1)%n];
                }
                if(a2[(i+1)%n]==0&&a2[(i-1+n)%n]!=0)
                {
                    a2[(i+1)%n]=a2[(i-1+n)%n];
                }
                if(a2[(i-1+n)%n]!=a2[(i+1)%n])
                {
                    patt=0;
                    break;
                }
            }
            else
            {
                if(a2[(i+1)%n]==0&&a2[(i-1+n)%n]!=0)
                {
                    if(a2[(i-1+n)%n]==1)
                        a2[(i+1)%n]=2;
                    else
                        a2[(i+1)%n]=1;
                }
                if(a2[(i-1+n)%n]==0&&a2[(i+1)%n]!=0)
                {
                    if(a2[(i+1)%n]==1)
                        a2[(i-1+n)%n]=2;
                    else
                        a2[(i-1+n)%n]=1;
                }
                if(a2[(i-1+n)%n]==a2[(i+1)%n])
                {
                    patt=0;
                    break;
                }
            }   
        }
        else if(a2[i]==2)
        {
            if(a[i]!='o')
            {
                if(a2[(i-1+n)%n]==0&&a2[(i+1)%n]!=0)
                {
                    a2[(i-1+n)%n]=a2[(i+1)%n];
                }
                if(a2[(i+1)%n]==0&&a2[(i-1+n)%n]!=0)
                {
                    a2[(i+1)%n]=a2[(i-1+n)%n];
                }
                if(a2[(i-1+n)%n]!=a2[(i+1)%n])
                {
                    patt=0;
                    break;
                }
            }
            else
            {
                if(a2[(i+1)%n]==0&&a2[(i-1+n)%n]!=0)
                {
                    if(a2[(i-1+n)%n]==1)
                        a2[(i+1)%n]=2;
                    else
                        a2[(i+1)%n]=1;
                }
                if(a2[(i-1+n)%n]==0&&a2[(i+1)%n]!=0)
                {
                    if(a2[(i+1)%n]==1)
                        a2[(i-1+n)%n]=2;
                    else
                        a2[(i-1+n)%n]=1;
                }
                if(a2[(i-1+n)%n]==a2[(i+1)%n])
                {
                    patt=0;
                    break;
                }
            }
        }
    }
    if(patt==-1)
    {
        int cr=0;
        for(int i=0;i<n;i++)
        {
            if(a2[i]!=0)
                cr++;
        }
        if(cr==n)
        {   
            for(int i=0;i<n;i++)
            {
                if(a2[i]==1)
                    cout<<"S";
                else
                    cout<<"W";
            }
            cout<<endl;
            return 0;
        }
       
    }
    patt=-1;
    for(int i=0;i<n;i++)
    {
        if(a3[i]==1)
        {
            if(a[i]=='o')
            {
                if(a3[(i-1+n)%n]==0&&a3[(i+1)%n]!=0)
                {
                    a3[(i-1+n)%n]=a3[(i+1)%n];
                }
                if(a3[(i+1)%n]==0&&a3[(i-1+n)%n]!=0)
                {
                    a3[(i+1)%n]=a3[(i-1+n)%n];
                }
                if(a3[(i-1+n)%n]!=a3[(i+1)%n])
                {
                    patt=0;
                    break;
                }
            }
            else
            {
                if(a3[(i+1)%n]==0&&a3[(i-1+n)%n]!=0)
                {
                    if(a3[(i-1+n)%n]==1)
                        a3[(i+1)%n]=2;
                    else
                        a3[(i+1)%n]=1;
                }
                if(a3[(i-1+n)%n]==0&&a3[(i+1)%n]!=0)
                {
                    if(a3[(i+1)%n]==1)
                        a3[(i-1+n)%n]=2;
                    else
                        a3[(i-1+n)%n]=1;
                }
                if(a3[(i-1+n)%n]==a3[(i+1)%n])
                {
                    patt=0;
                    break;
                }
            }   
        }
        else if(a3[i]==2)
        {
            if(a[i]!='o')
            {
                if(a3[(i-1+n)%n]==0&&a3[(i+1)%n]!=0)
                {
                    a3[(i-1+n)%n]=a3[(i+1)%n];
                }
                if(a3[(i+1)%n]==0&&a3[(i-1+n)%n]!=0)
                {
                    a3[(i+1)%n]=a3[(i-1+n)%n];
                }
                if(a3[(i-1+n)%n]!=a3[(i+1)%n])
                {
                    patt=0;
                    break;
                }
            }
            else
            {
                if(a3[(i+1)%n]==0&&a3[(i-1+n)%n]!=0)
                {
                    if(a3[(i-1+n)%n]==1)
                        a3[(i+1)%n]=2;
                    else
                        a3[(i+1)%n]=1;
                }
                if(a3[(i-1+n)%n]==0&&a3[(i+1)%n]!=0)
                {
                    if(a3[(i+1)%n]==1)
                        a3[(i-1+n)%n]=2;
                    else
                        a3[(i-1+n)%n]=1;
                }
                if(a3[(i-1+n)%n]==a3[(i+1)%n])
                {
                    patt=0;
                    break;
                }
            }
        }
    }
    if(patt==-1)
    {
        int cr=0;
        for(int i=0;i<n;i++)
        {
            if(a3[i]!=0)
                cr++;
        }
        if(cr==n)
        {   
            for(int i=0;i<n;i++)
            {
                if(a3[i]==1)
                    cout<<"S";
                else
                    cout<<"W";
            }
            cout<<endl;
            return 0;
        }
       
    }
    patt=-1;
    for(int i=0;i<n;i++)
    {
        if(a4[i]==1)
        {
            if(a[i]=='o')
            {
                if(a4[(i-1+n)%n]==0&&a4[(i+1)%n]!=0)
                {
                    a4[(i-1+n)%n]=a4[(i+1)%n];
                }
                if(a4[(i+1)%n]==0&&a4[(i-1+n)%n]!=0)
                {
                    a4[(i+1)%n]=a4[(i-1+n)%n];
                }
                if(a4[(i-1+n)%n]!=a4[(i+1)%n])
                {
                    patt=0;
                    break;
                }
            }
            else
            {
                if(a4[(i+1)%n]==0&&a4[(i-1+n)%n]!=0)
                {
                    if(a4[(i-1+n)%n]==1)
                        a4[(i+1)%n]=2;
                    else
                        a4[(i+1)%n]=1;
                }
                if(a4[(i-1+n)%n]==0&&a4[(i+1)%n]!=0)
                {
                    if(a4[(i+1)%n]==1)
                        a4[(i-1+n)%n]=2;
                    else
                        a4[(i-1+n)%n]=1;
                }
                if(a4[(i-1+n)%n]==a4[(i+1)%n])
                {
                    patt=0;
                    break;
                }
            }   
        }
        else if(a4[i]==2)
        {
            if(a[i]!='o')
            {
                if(a4[(i-1+n)%n]==0&&a4[(i+1)%n]!=0)
                {
                    a4[(i-1+n)%n]=a4[(i+1)%n];
                }
                if(a4[(i+1)%n]==0&&a4[(i-1+n)%n]!=0)
                {
                    a4[(i+1)%n]=a4[(i-1+n)%n];
                }
                if(a4[(i-1+n)%n]!=a4[(i+1)%n])
                {
                    patt=0;
                    break;
                }
            }
            else
            {
                if(a4[(i+1)%n]==0&&a4[(i-1+n)%n]!=0)
                {
                    if(a4[(i-1+n)%n]==1)
                        a4[(i+1)%n]=2;
                    else
                        a4[(i+1)%n]=1;
                }
                if(a4[(i-1+n)%n]==0&&a4[(i+1)%n]!=0)
                {
                    if(a4[(i+1)%n]==1)
                        a4[(i-1+n)%n]=2;
                    else
                        a4[(i-1+n)%n]=1;
                }
                if(a4[(i-1+n)%n]==a4[(i+1)%n])
                {
                    patt=0;
                    break;
                }
            }
        }
    }
    if(patt==-1)
    {
        int cr=0;
        for(int i=0;i<n;i++)
        {
            if(a4[i]!=0)
                cr++;
        }
        if(cr==n)
        {   
            for(int i=0;i<n;i++)
            {
                if(a4[i]==1)
                    cout<<"S";
                else
                    cout<<"W";
            }
            cout<<endl;
            return 0;
        }
       
    }
    cout<<-1<<endl;
    return 0;
}