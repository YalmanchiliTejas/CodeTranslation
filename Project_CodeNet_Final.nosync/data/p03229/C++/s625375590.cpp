#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n;
    vector <long long> a(n);
    vector <long long> b;
    vector <long long> c, d, e;
    long long ans, ans1, ans2, ans3, ans4;
    ans = 0;
    ans1 = 0;
    ans2 = 0;
    ans3 = 0;
    ans4 = 0;
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if(n == 3){
        b.push_back(a[1]);
        b.push_back(a[0]);
        b.push_back(a[2]);
        c.push_back(a[0]);
        c.push_back(a[2]);
        c.push_back(a[1]);
        for (int i=0; i<n-1; ++i){
            ans1 += llabs(b[i+1]-b[i]);
            ans2 += llabs(c[i+1]-c[i]);
        }
        ans = max(ans1, ans2);
    }
    else if(n % 2 == 1){
        m = n / 2;
        b.push_back(a[m]);
        c.push_back(a[m]);
        for(int i=0; i<m; ++i){
            b.push_back(a[n-1-i]);
            b.push_back(a[i]);
            c.push_back(a[i]);
            c.push_back(a[n-1-i]);
        }
        //for(int i=0; i<n; ++i){
        //    cout << c[i] << endl;
        //}
        for (int i=0; i<n-1; ++i){
            ans1 += llabs(b[i+1]-b[i]);
            ans2 += llabs(c[i+1]-c[i]);
        }
        if(ans1 >= ans2){
            ans = ans1;
        }
        else {
            ans = ans2;
        }
    }
    else {
        m = n / 2 - 1;
        b.push_back(a[m]);
        c.push_back(a[m+1]);
        d.push_back(a[m+1]);
        e.push_back(a[m]);
        for(int i=0; i<m; ++i){
            b.push_back(a[n-1-i]);
            b.push_back(a[i]);
            c.push_back(a[i]);
            c.push_back(a[n-1-i]);
            d.push_back(a[n-1-i]);
            d.push_back(a[i]);
            e.push_back(a[i]);
            e.push_back(a[n-1-i]);
        }
        b.push_back(a[m+1]);
        c.push_back(a[m]);
        d.push_back(a[m]);
        e.push_back(a[m+1]);
        for (int i=0; i<n-1; ++i){
            ans1 += llabs(b[i+1]-b[i]);
            ans2 += llabs(c[i+1]-c[i]);
            ans3 += llabs(d[i+1]-d[i]);
            ans4 += llabs(e[i+1]-e[i]);
        }
        ans = max(ans1, ans2);
        ans = max(ans, ans3);
        ans = max(ans, ans4);
        ans = max(ans, ans1);
    }
    cout << ans << endl;
}

