#include <iostream>

using namespace std;

int main() {

    int n, k;
    std::string str;
    std::cin >> n;
    std::cin >> str;
    std::cin >> k;


    char caracter = str[k-1];  //判定文字
//    std::cout << caracter << std::endl;
    //ok
    std::string result;


    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == caracter) {
//            result[i] = caracter;
            result.push_back(caracter);
//            cout << "a" << endl;
        } else {
//            result[i] = str[i];
            result.push_back('*');
//            cout << "b" << endl;
        }

    }


//    cout << ".size()" << result.size() << endl;
//    cout << ".length()" << result.length() << endl;
//    for (int j = 0; j < result.size(); ++j) {
//        cout<< result[j]<<endl;
//    }
    std::cout << result;

    return 0;
}