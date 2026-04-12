#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e5;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int arr[MAX],n;
string s;
vector<string>v;
void gen(string x)
{
    sort(x.begin(),x.end());
    do
    {
        v.push_back(x);
    }
    while(next_permutation(x.begin(),x.end()));
}
int val(char x)
{
    if(x=='S')
        return 1;
    return 2;
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    cin>>n>>s;
    gen("SSW");
    gen("SWW");
    v.push_back("SSS");
    v.push_back("WWW");
    for(int j=0; j<v.size(); j++)
    {
        arr[0]=val(v[j][0]);
        arr[1]=val(v[j][1]);
        arr[n-1]=val(v[j][2]);
        int f=1;
        for(int i=0; i<n; i++)
        {
            int l=i-1,r=i+1;
            if(l<0)
                l=n-1;
            if(r==n)
                r=0;
            if(arr[i]==1)
            {
                if(s[i]=='o')
                {

                    if(!arr[r])
                        arr[r]=arr[l];
                    else if(arr[r]!=arr[l])
                    {
                        f=0;
                        break;
                    }
                }
                else
                {
                    if(!arr[r])
                    {
                        if(arr[l]==1)
                            arr[r]=2;
                        else
                            arr[r]=1;
                    }
                    else if(arr[l]==arr[r])
                    {
                        f=0;
                        break;
                    }
                }
            }
            else
            {
                if(s[i]=='x')
                {
                    if(!arr[r])
                        arr[r]=arr[l];
                    else if(arr[r]!=arr[l])
                    {
                        f=0;
                        break;
                    }
                }
                else
                {
                    if(!arr[r])
                    {
                        if(arr[l]==1)
                            arr[r]=2;
                        else
                            arr[r]=1;
                    }
                    else if(arr[l]==arr[r])
                    {
                        f=0;
                        break;
                    }
                }
            }
        }
        if(f)
        {
            for(int i=0; i<n; i++)
            {

                if(arr[i]==1)
                    cout<<"S";
                else
                    cout<<"W";
            }
            cout<<endl;
            return 0;
        }
        for(int i=0; i<n; i++)
            arr[i]=0;
    }


    cout<<"-1"<<endl;



    return 0;
}
