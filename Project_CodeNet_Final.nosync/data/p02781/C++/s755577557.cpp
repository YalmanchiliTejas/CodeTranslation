#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,i0,n) for(int i=i0;i<n;++i)

int f1(string s1) {
    int m = s1.size();
    if(m<1) return 0;
    int h = stoi(s1.substr(0,1));
    return 9*(m-1) + h;
}

int f2(string s2) {
    int m = s2.size();
    if(m<2) return 0;
    int ret = 0;
    if(m>=3) ret += (m-1)*(m-2)/2*9*9;
    int h = stoi(s2.substr(0,1));
    ret += (h-1)*9*(m-1);
    rep2(i,1,m) {
        if(s2[i] != '0') {
            ret += f1(s2.substr(i));
            break;
        }
    }
    return ret;
}

int f3(string s3) {
    int m = s3.size();
    if(m<3) return 0;
    int ret = 0;
    if(m>=4) ret += (m-1)*(m-2)*(m-3)/3/2*9*9*9;
    int h = stoi(s3.substr(0,1));
    ret += (h-1)*(m-1)*(m-2)/2*9*9;
    rep2(i,1,m) {
        if(s3[i] != '0') {
            ret += f2(s3.substr(i));
            break;
        }
    }
    return ret;
}

int main()
{
    string s;
    int k;
    cin >> s >> k;

    int ans = 0;
    if(k==1) ans = f1(s);
    else if(k==2) ans = f2(s);
    else ans = f3(s);

    cout << ans << endl;
    return 0;
}