#include <iostream>
#include <bits/stdc++.h>
#define loop(N) for(int i=0;i<N;i++)
#define vi vector<int>
#define vs vector<string>
#define vl vector<long long int>
#define vpi vector<pair<int,int>>
#define msi map<string,int>
#define mil map<int,long long int>
#define lli long long int
#define ulli unsigned long long int

using namespace std ;
void ps(string i){
    cout << i << endl;
}

template <class T>
void pt(T s){
    cout << s << endl;
}

void pi(int i){
    cout << i << endl;
}

template <class T>
void pv(vector<T> v){
    loop(v.size()){
        pt<T>(v[i]);
    }
}

/*********************************reused****************************/
int main()
{
    ulli x,y,z;
    cin>>x>>y>>z;
    cout<<(x-z)/(y+z)<<endl;

   return 0;
}
