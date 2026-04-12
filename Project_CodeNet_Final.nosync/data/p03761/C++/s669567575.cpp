#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> FindCount(const string &str)
{
    vector<int> count(26, 0);
    for (const auto &ch : str) {
        count[ch - 'a'] += 1;
    }
    return count;
}

void Merge(const vector<int> &source, vector<int> &dest)
{
    for (size_t i = 0; i < dest.size(); i += 1) {
        dest[i] = min(dest[i], source[i]);
    }
}

string GetString(const vector<int> &count)
{
    string str = "";
    for (size_t i = 0; i < count.size(); i += 1) {
        str.append(count[i], 'a' + i);
    }
    return str;
}

int main()
{
    int n;
    cin >> n;
    cin.get();

    vector<int> count(26, (1 << 30));
    for (auto i = 0; i < n; i += 1) {
        string headline;
        getline(cin, headline);
        Merge(FindCount(headline), count);
    }

    cout << GetString(count) << "\n";
    return 0;
}
