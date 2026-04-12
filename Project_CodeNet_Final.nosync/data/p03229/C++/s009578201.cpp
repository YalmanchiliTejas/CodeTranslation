#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN = 1e5 + 10;
long long a[MAXN],ans[MAXN];
int main()
{
    int N;
  //  freopen("data.txt","r",stdin);
    //freopen("myanswer.txt","w",stdout);
    cin >>N;
    for(int i = 0 ;i < N; i ++)
    {
        cin >> a[i];
    }
    sort(a,a+N);
    //long long ans = 0;
    int mid = N/2;
    int l = 0,r = N-1;
    if(N%2!=0)
    {
        if(abs(a[mid-1]-a[mid])>abs(a[mid+1]-a[mid]))
        {
            int cnt = 0;
            ans[cnt] = a[mid];//0
            cnt++;
            ans[cnt] = a[mid-1];//1
            for(cnt = 2 ; cnt < N ; cnt++)
            {
                if(cnt%2 == 0)
                {
                    ans[cnt] = a[r];
                    r--;
                }
                else{
                    ans[cnt] = a[l];
                    l++;
                }
            }

        }
        else{
            int cnt = 0;
            ans[cnt] = a[mid];//0
            cnt++;
            ans[cnt] = a[mid+1];//1
            for(cnt = 2 ; cnt < N ; cnt++)
            {
                if(cnt%2 == 0)
                {
                    ans[cnt] = a[l];
                    l++;
                }
                else{
                    ans[cnt] = a[r];
                    r--;
                }
            }
        }

    }
    else{
        if(abs(a[mid]-a[l])>abs(a[mid-1]-a[r]))
       {
           int cnt = 0;
           ans[cnt] = a[mid];
           cnt++;
           ans[cnt] = a[l];
           l++;
           for(cnt = 2 ; cnt < N ; cnt++)
            {
                if(cnt%2 == 0)
                {
                    ans[cnt] = a[r];
                    r--;
                }
                else{
                    ans[cnt] = a[l];
                    l++;
                }
            }
       }
       else{
            int cnt = 0;
            ans[cnt] = a[mid-1];//0
            cnt++;
            ans[cnt] = a[r];//1
            r--;
            for(cnt = 2 ; cnt < N ; cnt++)
            {
                if(cnt%2 == 0)
                {
                    ans[cnt] = a[l];
                    l++;
                }
                else{
                    ans[cnt] = a[r];
                    r--;
                }
            }
       }
    }
    long long Ans= 0;
    for(int i = 1 ; i < N ; i++)
    {
        //cout<<a[i]<<" ";
        Ans += abs(ans[i]-ans[i-1]);

    }
    cout<<Ans<<endl;
    return 0;
}
