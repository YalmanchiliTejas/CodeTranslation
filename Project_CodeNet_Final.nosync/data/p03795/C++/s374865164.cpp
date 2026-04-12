#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string code[] = {
    "<", "DO",
    "<", "VARS", "<", "0", ">", "<", "0", ">", ">",
    "<", "IN", "<", "0", ">", ">",
    "<", "VARS", "<", "1", ">", "<", "MUL", "<", "800", ">", "<", "VAR", "<", "0", ">", ">", ">", ">",
    "<", "VARS", "<", "2", ">", "<", "MUL", "<", "200", ">", "<", "DIV", "<", "VAR", "<", "0", ">", ">", "<", "15", ">", ">", ">", ">",
    "<", "VARS", "<", "3", ">", "<", "SUB", "<", "VAR", "<", "1", ">", ">", "<", "VAR", "<", "2", ">", ">", ">", ">",
    "<", "OUT", "<", "VAR", "<", "3", ">", ">", ">",
    ">"};

int number[112345];

pair<int, int> runPart(int first)
{
    int i = first + 1;
    int res = 0;

    pair<int, int> val;

    string str = code[i];

    if (str == "DO")
    {
        i++;
        while (code[i] != ">")
            i = runPart(i).second + 1;
    }
    else if (str == "REP")
    {
        i++;
        val = runPart(i);
        for (int j = 0; j < val.first; j++)
            i = runPart(val.second + 1).second + 1;
    }
    else if (str == "IN")
    {
        i++;
        int input;
        cin >> input;
        val = runPart(i);
        number[val.first] = input;
        i = val.second + 1;
    }
    else if (str == "OUT")
    {
        i++;
        val = runPart(i);
        cout << val.first << endl;
        i = val.second + 1;
    }
    else if (str == "VAR")
    {
        i++;
        val = runPart(i);
        res = number[val.first];
        i = val.second + 1;
    }
    else if (str == "VARS")
    {
        i++;
        val = runPart(i);
        int index = val.first;
        i = val.second + 1;
        val = runPart(i);
        number[index] = val.first;
        i = val.second + 1;
    }
    else if (str == "SUM")
    {
        i++;
        val = runPart(i);
        res = val.first;
        i = val.second + 1;
        val = runPart(i);
        res += val.first;
        i = val.second + 1;
    }
    else if (str == "SUB")
    {
        i++;
        val = runPart(i);
        res = val.first;
        i = val.second + 1;
        val = runPart(i);
        res -= val.first;
        i = val.second + 1;
    }
    else if (str == "MUL")
    {
        i++;
        val = runPart(i);
        res = val.first;
        i = val.second + 1;
        val = runPart(i);
        res *= val.first;
        i = val.second + 1;
    }
    else if (str == "DIV")
    {
        i++;
        val = runPart(i);
        res = val.first;
        i = val.second + 1;
        val = runPart(i);
        res /= val.first;
        i = val.second + 1;
    }
    else
    {
        res = stoi(code[i]);
        i++;
    }

    return {res, i};
}

int main()
{
    memset(number, 0, sizeof(number));

    runPart(0);

    return 0;
}