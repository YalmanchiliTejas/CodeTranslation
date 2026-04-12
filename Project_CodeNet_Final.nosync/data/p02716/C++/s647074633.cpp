    #include <bits/stdc++.h>
    using namespace std;
     
     
    int main() {
    long long n;
    cin >> n;
    vector<long long> p;
    vector<long long> q;
      long long s=0;
      for(int i = 0;i < n;i++){
        long long a;
        cin >> a;
       if(i%2==0)p.push_back(a);
        else {q.push_back(a);s+=a;}
      }
      if(n%2==0){
        long long t=0;
        long long h=0;
        for(int i = 0;i < n/2;i++){
          h += p.at(i)-q.at(i);
          t = max(h,t);
        }
        cout << s+t << endl;}
          else{
         vector <long long> t(n/2+1);
         vector <long long> r(n/2+1);
        long long h=0;
        for(int i = 0;i < n/2;i++){
          h += p.at(i)-q.at(i);
          t.at(i+1) = max(h,t.at(i));
        }
        h = 0;
        for(int i = n/2-1;i > -1;i--){
          h += p.at(i+1)-q.at(i);
          r.at(i) = max(h,r.at(i+1));
        } 
        long long ans = 0;
        for(int i = 0;i < n/2+1;i++){
          ans = max(t.at(i)+r.at(i),ans);
        }
            cout << ans+s << endl;
          }
    }  