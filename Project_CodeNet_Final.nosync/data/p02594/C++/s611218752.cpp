// Solution by ** Abhishek Mittal **
#include<iostream>
#include<fstream>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<math.h>

#define FIO ios_base::sync_with_stdio(0);  cin.tie(0);
#define PI 3.14159265358979323846
#define mod 1000000007
#define ll long long
#define vll vector<long long>  

#define all(c) c.begin(), c.end()

// Used to traverse in any STL container with iterators
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

// Find whether element is present in given container or not
#define present(container, element) (container.find(element) != container.end())

// Finds whether element in present container is present in vector or not
#define cpresent(container, element) (find(all(container),element) != container.end())

using namespace std;

const ll mxlen = 1e6;

// vector<int> adj(mxlen);

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    FIO
    int n;
    cin>>n;
    if(n>=30)cout<<"Yes";
    else cout<<"No";

    return 0;
}