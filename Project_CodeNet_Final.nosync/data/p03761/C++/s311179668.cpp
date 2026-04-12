#include <bits/stdc++.h>
using namespace std;
int m[26][55];
int N;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        string s;
        cin>>s;
        for(char c:s){
            m[c-'a'][i]++;
        }
    }
    for(int i=0;i<26;i++){
       int me = *min_element(m[i],m[i]+N);
       while(me--)cout<<(char)(i+'a');
    }
    return 0;
}
