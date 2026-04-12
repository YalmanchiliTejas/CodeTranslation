#include <bits/stdc++.h>
using namespace std;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

typedef long long ll;

ll INF = 100000000000000;
ll MOD = 1e9+7;

ll N;
string S;

bool judge(string S,vector<char>& A){
    int N = A.size();
    bool frag = 0;
    for(int i = 1;i < N-1;i++){
        if(i != N-1){
            if(A[i] == 'S'){
                if(S[i] == 'o'){
                    A[i+1] = A[i-1];
                }else{
                    if(A[i-1] == 'S'){
                        A[i+1] = 'W';
                    }else{
                        A[i+1] = 'S';
                    }
                }
            }else{
                 if(S[i] == 'o'){
                     if(A[i-1] == 'S'){
                         A[i+1] = 'W';
                     }else{
                         A[i+1] = 'S';
                     }
                 }else{
                     A[i+1] = A[i-1];
                 }
            }
        }
    }
    if(A[N-1] == 'S'){
        if(S[N-1] == 'o'){
            if(A[N-2] == A[0]){
                frag = true;
            }
        }else{
            if(A[N-2] != A[0]){
                frag = true;
            }
        }
    }else{
        if(S[N-1] == 'o'){
            if(A[N-2] != A[0]){
                frag= true;
            }
        }else{
            if(A[N-2] == A[0]){
                frag = true;
            }
        }
    }
    if(A[0] == 'S'){
        if(S[0] == 'o'){
            if(A[N-1] != A[1]){
                frag = false;
            }
        }else{
            if(A[N-1] == A[1]){
                frag = false;
            }
        }
    }else{
        if(S[0] == 'o'){
            if(A[N-1] == A[1]){
                frag = false;
            }
        }else{
            if(A[N-1] != A[1]){
                frag = false;
            }
        }
    }
    if(frag){
        return true;
    }else{
        return false;
    }
}


int main(){
   cin >> N >> S;
   vector<char> case1(N),case2(N),case3(N),case4(N);
   case1[0] = 'S';case1[1] = 'S';
   case2[0] = 'S';case2[1] = 'W';
   case3[0] = 'W';case3[1] = 'S';
   case4[0] = 'W';case4[1] = 'W';
   if(judge(S,case1)){
       for(int i = 0;i < N;i++){
           cout << case1[i];
       }
       cout << endl;
       return 0;
   }
   if(judge(S,case2)){
       for(int i = 0;i < N;i++){
           cout << case2[i];
       }
       cout << endl;
       return 0;
   }
   if(judge(S,case3)){
       for(int i = 0;i < N;i++){
           cout << case3[i];
       }
       cout << endl;
       return 0;
   }
   if(judge(S,case4)){
       for(int i = 0;i < N;i++){
           cout << case4[i];
       }
       cout << endl;
       return 0;
   }
   cout << -1 << endl;
}

