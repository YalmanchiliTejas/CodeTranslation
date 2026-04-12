
 #include <bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(false);cin.tie(0);
#define setnow clock_t tStart=clock();
#define time (double)(clock() - tStart)/CLOCKS_PER_SEC;
#define setin(x) ifstream cin(x);
#define setout(x) ofstream cout(x);
typedef long long ll;
typedef long long int lli;
typedef pair < int, int> dbl;
 #define mod 1000000007

const int maxInt = 1e9*2;
const lli maxLong = 1e18*2;
char one[101010];
char two[101010];
char three[101010];
char four[101010];
char rev(char ch){
    if(ch == 'S')
        return 'W';
    else return 'S';
}
string str;
void solve(int n, char one[]){
 for(int i=0;i<n;i++){
                if(str[i] == 'o'){
                        if(one[i]=='S'){
                            if(i == 0)
                                one[n-1]=one[i+1];
                            else
                                one[i+1] = one[i-1];
                        } else {
                            if(i == 0)
                                one[n-1] = rev(one[i+1]);
                            else
                                one[i+1] = rev(one[i-1]);
                        }
                } else {
                        if(one[i]=='W'){
                            if(i == 0)
                                one[n-1]=one[i+1];
                            else
                                one[i+1] = one[i-1];
                        } else {
                            if(i == 0)
                                one[n-1] = rev(one[i+1]);
                            else
                                one[i+1] = rev(one[i-1]);
                        }
                }
            }
}

bool check(int n, char one[]){
    for(int i=0;i<n;i++){
            if(one[i]=='S'){
                    if(str[i]=='o'){
                        if(i == 0){
                            if(one[n-1] != one[i+1])
                                    return 0;
                        } else if(i == n-1){
                                if(one[i-1] != one[0])
                                    return 0;
                        } else if(one[i-1] != one[i+1])
                                    return 0;
                    } else {
                        if(i == 0){
                            if(one[n-1] == one[i+1])
                                    return 0;
                        } else if(i == n-1){
                                if(one[i-1] == one[0])
                                    return 0;
                        } else if(one[i-1] == one[i+1])
                                    return 0;
                    }
            } else {
                     if(str[i]=='x'){
                        if(i == 0){
                            if(one[n-1] != one[i+1])
                                    return 0;
                        } else if(i == n-1){
                                if(one[i-1] != one[0])
                                    return 0;
                        } else if(one[i-1] != one[i+1])
                                    return 0;
                    } else {
                        if(i == 0){
                            if(one[n-1] == one[i+1])
                                    return 0;
                        } else if(i == n-1){
                                if(one[i-1] == one[0])
                                    return 0;
                        } else if(one[i-1] == one[i+1])
                                    return 0;
                    }
            }
    }
    return 1;
}
int main(){
            int n;
            cin >> n;
            cin >> str;
           one[0]='S';
           one[1]='S';
           //
           two[0]='S';
           two[1]='W';
            //
           three[0]='W';
           three[1]='S';
            //
            four[0]='W';
            four[1]='W';
            //bool ok = true;
            solve(n, one);
            solve(n, two);
            solve(n, three);
            solve(n, four);
            if(check(n,one)){
                for(int i=0;i<n;i++)
                    cout<<one[i];
              // cout<<endl;
                return(0);
            }
            if(check(n,two)){
                for(int i=0;i<n;i++)
                    cout<<two[i];
                return(0);
            }
            if(check(n,three)){
                for(int i=0;i<n;i++)
                    cout<<three[i];
                return(0);
            }
            if(check(n,four)){
                for(int i=0;i<n;i++)
                    cout<<four[i];
                return(0);
            }
            return cout<<-1,0;

}
