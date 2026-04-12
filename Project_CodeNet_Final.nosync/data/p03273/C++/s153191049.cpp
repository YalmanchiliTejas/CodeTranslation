        #include <bits/stdc++.h>
        using namespace std;
        #define int long long
const int MAX = 1000001;
const int MOD = 1000000007;
   
        signed main() {
           int h,w;
           cin>>h>>w;
           string v,p;
           for(int i=0;i<w;i++)v.push_back('.');
    vector<string> a,b;
    for(int i=0;i<h;i++){
        cin>>p;
        if(p!=v)a.push_back(p);
    }
    v.clear();for(int i=0;i<a.size();i++)v.push_back('.');
    for(int i=0;i<w;i++){
        p.clear();
        for(int j=0;j<a.size();j++){
            p.push_back(a[j][i]);
        }
      if(v!=p) b.push_back(p);
    }
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++)cout<<b[j][i];
        cout<<endl;
    }

         return 0;

        }
