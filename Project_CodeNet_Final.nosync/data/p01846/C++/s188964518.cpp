#include <bits/stdc++.h>
using namespace std;

inline std::vector<std::string> split(const std::string &str, char sep)
{
    std::vector<std::string> v;
    std::stringstream ss(str);
    std::string buffer;
    while( std::getline(ss, buffer, sep) ) {
        v.push_back(buffer);
    }
    return v;
}

int w = 0,h = 0;

inline string make_jfen(bool *ball){

    string ret = "";

    int counter = 0;
    for(int j=0; j<w; j++){
        if(ball[j]){
            if(counter != 0){
                stringstream ss;
                ss << counter;
                char num_c;
                ss >> num_c;
                ret += num_c;
                counter = 0;
            }
            ret += 'b';
        }
        else if(!ball[j]){
            counter++;
        }
    }
    if(counter != 0){
        stringstream ss;
        ss << counter;
        char num_c;
        ss >> num_c;
        ret += num_c;
        counter = 0;
    }

    return ret;

}

/*
inline string make_jfen(bool *ball){

    string ret = "";
    bool flag =false;
    for(int j=0; j<w; j++){
        if(ball[j]){
            flag = true;
            break;
        }
    }
    if(!flag){
        stringstream ss;
        ss << w;
        char num_c;
        ss >> num_c;
        ret += num_c;
    }
    else if(flag){
        int counter = 0;
        for(int j=0; j<w; j++){
            if(ball[j]){
                if(counter != 0){
                    stringstream ss;
                    ss << counter;
                    char num_c;
                    ss >> num_c;
                    ret += num_c;
                    counter = 0;
                }
                ret += 'b';
            }
            else if(!ball[j]){
                counter++;
            }
        }
        if(counter != 0){
            stringstream ss;
            ss << counter;
            char num_c;
            ss >> num_c;
            ret += num_c;
            counter = 0;
        }
    }
    return ret;

}
//*/

bool avoid_ball[10],insert_ball[10];

int main() {


    while(true){

        string s;
        cin >> s;
        if(s == "#"){
            break;
        }

        vector<string> vec = split(s,'/');

        w = 0;
        h = vec.size();

        for(char c : vec[0]){
            if(c == 'b'){
                w++;
                continue;
            }
            stringstream ss;
            ss << c;
            int tmp;
            ss >> tmp;
            w += tmp;
        }

        int a,b,c,d;

        cin >> a >> b >> c >> d;

        a--;
        b--;
        c--;
        d--;

        if(a != c){
            int index=0;
            memset(avoid_ball, false, sizeof(avoid_ball));
            for(char cc : vec[a]){
                if(cc == 'b'){
                    avoid_ball[index] = true;
                    index++;
                    continue;
                }
                stringstream ss;
                ss << cc;
                int tmp;
                ss >> tmp;
                index += tmp;
            }
            avoid_ball[b] = false;
            vec[a] = make_jfen(avoid_ball);

            memset(insert_ball, false, sizeof(insert_ball));
            index = 0;
            for(char cc : vec[c]){
                if(cc == 'b'){
                    insert_ball[index] = true;
                    index++;
                    continue;
                }
                stringstream ss;
                ss << cc;
                int tmp;
                ss >> tmp;
                index += tmp;
            }
            insert_ball[d] = true;
            vec[c] = make_jfen(insert_ball);
        }
        else if(a == c){

            memset(avoid_ball, false, sizeof(avoid_ball));
            int index=0;
            for(char cc : vec[a]){
                if(cc == 'b'){
                    avoid_ball[index] = true;
                    index++;
                    continue;
                }
                stringstream ss;
                ss << cc;
                int tmp;
                ss >> tmp;
                index += tmp;
            }

            avoid_ball[b] = false;
            avoid_ball[d] = true;

            vec[a] = make_jfen(avoid_ball);

        }

        string ans = "";

        for(int i=0; i<h; i++){
            ans += vec[i];
            if(i+1 != h){
                ans += '/';
            }
        }

        cout << ans << endl;


    }
    return 0;
}
