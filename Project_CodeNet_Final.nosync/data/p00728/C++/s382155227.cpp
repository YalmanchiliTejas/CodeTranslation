#include<iostream>
#include<numeric>
#include<algorithm>
using namespace std;
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
int main(){
    int N,C;
    int ma,mi;
    while(cin>>N&&N>0){
        C=0;
        int a[N];
        for (int i = 0;i < N;++i) {
            cin >> a[i];
        }
        ma = *max_element(a, a + SIZE_OF_ARRAY(a));
        mi = *min_element(a, a + SIZE_OF_ARRAY(a));
        C = accumulate(a, a + SIZE_OF_ARRAY(a), 0);
        C -= mi;
        C -= ma;
        cout << C /(N-2)<< endl;
    }
}
