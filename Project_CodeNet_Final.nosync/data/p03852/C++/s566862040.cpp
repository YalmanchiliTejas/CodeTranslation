    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
      char S;
      char check[100] = {'a', 'i' ,'u', 'e', 'o'};
      bool flag = false;
      cin >> S;
     
      for (int i = 0; i < 5; i++){
        if (S == check[i]) flag = true;
      }
      
      if(flag) {
        cout << "vowel" << endl;
      } else {
        cout << "consonant" << endl;
      }

    }