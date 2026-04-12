#include<iostream>

#include<cmath>
#include<string>
#include <algorithm> 

using namespace std;

# define p(s) cout << s << endl;
# define printIf(j,s1,s2) cout << (j ? s1 : s2) << endl;
# define YES(j) cout << (j ? "YES" : "NO") << endl;
# define Yes(j) cout << (j ? "Yes" : "No") << endl;

string lpad(string l,int s,int n){
    string temp = to_string(n);
    string res = "";
    int loop = s - temp.size();
    while(loop--) res+=l;

    return res+temp;
}

int main()
{
    int x;
    cin >> x ;

    YES(x==3 || x==5 || x==7)

}