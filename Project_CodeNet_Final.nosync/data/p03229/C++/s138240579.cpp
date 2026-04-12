#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ll n; cin>>n;
    vector <ll> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    vector <ll> a,b,ans1,ans2;
    ll sum1=0,sum2=0;
    ll temp1=0,temp2=0;
    if(n&1) {
        ans1.push_back(arr[n/2]);
        ans2.push_back(arr[n/2]);
        for (int i = 0; i < n/2; ++i)
        {
            a.push_back(arr[i]);
        } for (int i = n/2 + 1; i < n; ++i)
        {
            b.push_back(arr[i]);
        } ll inda=0,indb=0,indbb=b.size()-1;
        for (int i = 0; i < n-1; ++i)
        {
            if(i&1) {
                ans2.push_back(a[inda]);
                ans1.push_back(a[inda]);
                inda++;
            } else {
                ans2.push_back(b[indb++]);
                ans1.push_back(b[indbb--]);
            }
        }

        for (int i = 1; i < ans1.size(); ++i)
        {
            sum1 += abs(ans2[i]-ans2[i-1]);
            sum2 += abs(ans1[i]-ans1[i-1]);
        }
        temp1=max(sum1,sum2);

        reverse(arr.begin(),arr.end());
        sum1=0,sum2=0;
        a.clear(); b.clear(); ans2.clear(); ans1.clear();
        ans1.push_back(arr[n/2]);
        ans2.push_back(arr[n/2]);
        for (int i = 0; i < n/2; ++i)
        {
            a.push_back(arr[i]);
        } for (int i = n/2 + 1; i < n; ++i)
        {
            b.push_back(arr[i]);
        }  inda=0,indb=0,indbb=b.size()-1;
        for (int i = 0; i < n-1; ++i)
        {
            if(i&1) {
                ans2.push_back(a[inda]);
                ans1.push_back(a[inda]);
                inda++;
            } else {
                ans2.push_back(b[indb++]);
                ans1.push_back(b[indbb--]);
            }
        }

        for (int i = 1; i < ans1.size(); ++i)
        {
            sum1 += abs(ans2[i]-ans2[i-1]);
            sum2 += abs(ans1[i]-ans1[i-1]);
        }
        temp2=max(sum1,sum2);
        cout<<max(temp1,temp2);

    } else {
        for (int i = 0; i < n/2; ++i)
        {
            a.push_back(arr[i]);
        } for (int i = n/2 ; i < n; ++i)
        {
            b.push_back(arr[i]);
        } ll inda=0,indb=0,indbb=b.size()-1;
        for (int i = 0; i < n; ++i)
        {
            if(i&1) {
                ans2.push_back(a[inda]);
                ans1.push_back(a[inda]);
                inda++;
            } else {
                ans2.push_back(b[indb++]);
                ans1.push_back(b[indbb--]);
            }
        }

        for (int i = 1; i < ans1.size(); ++i)
        {
            sum1 += abs(ans2[i]-ans2[i-1]);
            sum2 += abs(ans1[i]-ans1[i-1]);
        }
        temp1=max(sum1,sum2);

        reverse(arr.begin(),arr.end());
        sum1=0,sum2=0;
        a.clear(); b.clear(); ans2.clear(); ans1.clear();

        for (int i = 0; i < n/2; ++i)
        {
            a.push_back(arr[i]);
        } for (int i = n/2 ; i < n; ++i)
        {
            b.push_back(arr[i]);
        }  inda=0,indb=0,indbb=b.size()-1;
        for (int i = 0; i < n; ++i)
        {
            if(i&1) {
                ans2.push_back(a[inda]);
                ans1.push_back(a[inda]);
                inda++;
            } else {
                ans2.push_back(b[indb++]);
                ans1.push_back(b[indbb--]);
            }
        }



        for (int i = 1; i < ans1.size(); ++i)
        {
            sum1 += abs(ans2[i]-ans2[i-1]);
            sum2 += abs(ans1[i]-ans1[i-1]);
        }
        temp2=max(sum1,sum2);
        cout<<max(temp1,temp2);
    }
    return 0;
}