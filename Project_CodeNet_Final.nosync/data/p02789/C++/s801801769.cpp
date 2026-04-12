#include <iostream>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define vi vector<int>

#define ll long long int

int ctoi(char c) {return c-'0';}
int ord(char c) {return c-'a';}
int len(string s) {return s.length();}
int itoc(int i) {return i+'a';}

int main() {
int N,M;
cin>>N>>M;
cout<<(N==M ? "Yes" : "No")<<endl;
return 0;
}
