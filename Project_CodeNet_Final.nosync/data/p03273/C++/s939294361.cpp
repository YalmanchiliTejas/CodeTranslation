 #include<bits/stdc++.h>
 #include<vector>
 using namespace std;

 int main() {
   int h, w;
   cin >> h >> w;
   vector<string> a(h);
   for (int i = 0; i < h; i++) {
    cin >> a[i];
   }

   vector<bool> s(h, false);
   vector<bool> t(w, false);

   for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
       if (a[i][j] == '#') {
         s[i] = true;
         t[j] = true;
       }
    }
   }

   for (int i = 0; i < h; i++) {
     if (s[i]) {
       for (int j = 0; j < w; j++) {
         if (t[j]) {
           cout << a[i][j];
         }
       }
       cout <<"\n";
     }
   }
 }