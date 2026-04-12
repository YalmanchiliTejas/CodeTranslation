#include <iostream>
#include <string>

bool check(int N, const std::string& s, std::string& t){
    for(int i = 2; i < N; i++){
        if(s.at(i-1) == 'o' && t.at(i-1) == 'S'){
            t.at(i) = t.at(i-2);
        }else if(s.at(i-1) == 'o' && t.at(i-1) == 'W'){
            t.at(i) = t.at(i-2) == 'S' ? 'W' : 'S';
        }else if(s.at(i-1) == 'x' && t.at(i-1) == 'S'){
            t.at(i) = t.at(i-2) == 'S' ? 'W' : 'S';
        }else if(s.at(i-1) == 'x' && t.at(i-1) == 'W'){
            t.at(i) = t.at(i-2);
        }
    }
    bool f = false;
    if(s.at(0) == 'o' && t.at(0) == 'S'){
        if(t.at(N-1) == t.at(1)) f = true;
    }else if(s.at(0) == 'o' && t.at(0) == 'W'){
        if(t.at(N-1) != t.at(1)) f = true;
    }else if(s.at(0) == 'x' && t.at(0) == 'S'){
        if(t.at(N-1) != t.at(1)) f = true;
    }else if(s.at(0) == 'x' && t.at(0) == 'W'){
        if(t.at(N-1) == t.at(1)) f = true;
    }
    if(!f) return false;
    f = false;
    if(s.at(N-1) == 'o' && t.at(N-1) == 'S'){
        if(t.at(0) == t.at(N-2)) f = true;
    }else if(s.at(N-1) == 'o' && t.at(N-1) == 'W'){
        if(t.at(0) != t.at(N-2)) f = true;
    }else if(s.at(N-1) == 'x' && t.at(N-1) == 'S'){
        if(t.at(0) != t.at(N-2)) f = true;
    }else if(s.at(N-1) == 'x' && t.at(N-1) == 'W'){
        if(t.at(0) == t.at(N-2)) f = true;
    }
    if(!f) return false;
    return true;
}

int main(int argc, char **argv)
{
    int N;
    std::string s;
    
    std::cin >> N >> s;

    {
        std::string t(N, ' ');
        t.at(0) = 'S'; t.at(1) = 'S'; // assumption
        bool flag = check(N, s, t);
        if(flag){
            std::cout << t << std::endl;
            return 0;
        }
    }
    {
        std::string t(N, ' ');
        t.at(0) = 'S'; t.at(1) = 'W'; // assumption
        bool flag = check(N, s, t);
        if(flag){
            std::cout << t << std::endl;
            return 0;
        }
    }
    {
        std::string t(N, ' ');
        t.at(0) = 'W'; t.at(1) = 'S'; // assumption
        bool flag = check(N, s, t);
        if(flag){
            std::cout << t << std::endl;
            return 0;
        }
    }
    {
        std::string t(N, ' ');
        t.at(0) = 'W'; t.at(1) = 'W'; // assumption
        bool flag = check(N, s, t);
        if(flag){
            std::cout << t << std::endl;
            return 0;
        }
    }
    
    std::cout << -1 << std::endl;
    
    
}
