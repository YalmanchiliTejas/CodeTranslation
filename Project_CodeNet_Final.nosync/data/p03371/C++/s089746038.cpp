#include <iostream>

int max(int a, int b) {
    if(a>b) return a;
    else return b;
}
int min(int a, int b) {
    if(a<b) return a;
    else return b;
}
int abs(int a, int b) {
    if(a>b) return a-b;
    else return b-a;
}


using namespace std;
int main(int argc, const char * argv[]) {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    
    int each = A*X + B*Y;
    
    int mix1, mix2;
    
    mix1 = C*min(X,Y)*2 + (X>Y ? A : B)*abs(X,Y);
    mix2 = C*max(X,Y)*2;
    
    cout << min(min(each, mix1), mix2);
    return 0;
}
