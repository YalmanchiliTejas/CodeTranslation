#include <bits/stdc++.h>
#define ll long long
#define all(a) (a).begin(),(a).end()

using namespace std;

int main(int argc, char const *argv[]) {
    string S;
    std::cin >> S;
    for (size_t i = 0; i < S.size(); i++) {
        if(S[i]=='A' && i!=S.size()-1){
            if(S[i+1]=='C'){
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
  return 0;
}
