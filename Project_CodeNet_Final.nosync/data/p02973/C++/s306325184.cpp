#include<iostream>
#include<algorithm>
using namespace std;
int num[100010],n;
int Ansb;
namespace Task2{
    int a[100010];
    int r=0;
    void main(){
        for(int i=0;i<n;i++){
            int *p=upper_bound(a,a+r,num[i],greater<int>());
            if(p-a==r)
                r++;
            *p=num[i];
        }
    }
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>num[i];
    Task2::main();
    Ansb=Task2::r;
    cout<<Ansb;
    return 0;
}