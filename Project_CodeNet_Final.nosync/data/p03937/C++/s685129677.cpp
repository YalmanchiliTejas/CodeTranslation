#include<iostream> 
#include<vector> 

using std::cin;
using std::cout; 
using std::vector; 

int main() { 
    int h, w; 
    cin >> h >> w; 
    vector<vector<int>> strings(h); 
    for (auto& string : strings) { 
        string.assign(w, '#'); 
        for (auto& symbol : string) { 
            char input_symbol; 
            cin >> input_symbol; 
            symbol = input_symbol; 
        }
    }
    if (strings[0][0] != '#') { 
        cout << "Impossible\n"; 
        return 0; 
    }
    int i = 0; 
    int j = 0; 
    while (!((i == h - 1) && (j == w - 1))) { 
        bool down = false; 
        if (i < h - 1) { 
            down = (strings[i + 1][j] == '#'); 
        }
        bool right = false; 
        if (j < w - 1) { 
            right = (strings[i][j + 1] == '#'); 
        }
        if (down && right) { 
            cout << "Impossible\n"; 
            return 0; 
        }
        strings[i][j] = '.'; 
        if (down) { 
            ++i; 
        } else if (right){ 
            ++j; 
        } else { 
            cout << "Impossible\n"; 
            return 0;
        }
    }
    if (strings[h - 1][w - 1] != '#') { 
        cout << "Impossible\n"; 
        return 0; 
    } 
    strings[h - 1][w - 1] = '.'; 
    for (const auto& string : strings) { 
        for (const auto symbol : string) { 
            if (symbol != '.') { 
                cout << "Impossible\n"; 
                return 0; 
            }
        }
    }
    cout << "Possible\n"; 
    return 0; 
}
                        
                    
                    
