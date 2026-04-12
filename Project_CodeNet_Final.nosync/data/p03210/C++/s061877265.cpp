    #include <iostream>
    using namespace std;
    int main() {
        int a;
        cin >> a;
     
        switch(a){
        case 3:
        case 5:
        case 7:
            cout << "YES" << endl;
            break;
        default:
            cout << "NO" << endl;
            break;
        }
        
        return 0;
    }