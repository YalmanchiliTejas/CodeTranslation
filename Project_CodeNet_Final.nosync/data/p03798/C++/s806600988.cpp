#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

bool ok(std::string& res, const std::string& s, const unsigned int N){
const char original = res[N-1];
for (unsigned int i = 1; i < N-1; ++i){
if ((res[i] == 'S' && s[i] == 'o') || (res[i] == 'W' && s[i] == 'x')){
res[i+1] = res[i-1];
}
else if (res[i-1] == 'S'){
res[i+1] = 'W';
}
else {
res[i+1] = 'S';
}
}

if (res[N-1] != original){
return false;
}

if (res[N-1] == 'S'){
if (s[N-1] == 'o' && res[N-2] != res[0]){
return false;
}

if (s[N-1] == 'x' && res[N-2] == res[0]){
return false;
}
}

if (res[N-1] == 'W'){
if (s[N-1] == 'o' && res[N-2] == res[0]){
return false;
}

if (s[N-1] == 'x' && res[N-2] != res[0]){
return false;
}
}


return true;
}

int main(){
std::string line;

std::getline(std::cin, line);
const unsigned int N = atoi(line.c_str());

std::getline(std::cin, line);
const std::string s = line;

std::string res = s;

if (s[0] == 'o'){
res[0] = 'S';
res[N-1] = 'S';
res[1] = 'S';
if (ok(res, s, N)){
std::cout << res << std::endl;
return 0;
}

res[0] = 'S';
res[N-1] = 'W';
res[1] = 'W';
if (ok(res, s, N)){
std::cout << res << std::endl;
return 0;
}

res[0] = 'W';
res[N-1] = 'S';
res[1] = 'W';
if (ok(res, s, N)){
std::cout << res << std::endl;
return 0;
}

res[0] = 'W';
res[N-1] = 'W';
res[1] = 'S';
if (ok(res, s, N)){
std::cout << res << std::endl;
return 0;
}

}


if (s[0] == 'x'){
res[0] = 'S';
res[N-1] = 'S';
res[1] = 'W';
if (ok(res, s, N)){
std::cout << res << std::endl;
return 0;
}

res[0] = 'S';
res[N-1] = 'W';
res[1] = 'S';
if (ok(res, s, N)){
std::cout << res << std::endl;
return 0;
}

res[0] = 'W';
res[N-1] = 'S';
res[1] = 'S';
if (ok(res, s, N)){
std::cout << res << std::endl;
return 0;
}

res[0] = 'W';
res[N-1] = 'W';
res[1] = 'W';
if (ok(res, s, N)){
std::cout << res << std::endl;
return 0;
}

}



std::cout << "-1" << std::endl;

return 0;
}