#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main() {
    std::string line;
    std::getline(std::cin, line);
    std::vector<string> strings;
    std::istringstream f(line);
    std::string _r;
	std::string _g;
	std::string _b;
    getline(f, _r, ' ');
	getline(f, _g, ' ');
	getline(f, _b, ' ');
	int r = stoi(_r);
	int g = stoi(_g);
	int b = stoi(_b);
	int result = 100 * r + 10 * g + b;
	if (result % 4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
    return 0;
}