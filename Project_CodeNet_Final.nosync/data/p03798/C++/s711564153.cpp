#include<bits/stdc++.h>
using namespace std;
 
int main() {
int N;
string str;
cin >> N >> str;
bool nxor[N];
for (int i = 0; i < N; i++) {
nxor[i] = (str[i] == 'o');
}
int line[N];
line[0] = 0;
line[1] = 0;
for (int i = 2; i < N; i++) {
if (line[i-1] == 0) {
line[i] = (nxor[i-1] ? line[i-2] : ~line[i-2]);
}
else {
line[i] = (nxor[i-1] ? ~line[i-2] : line[i-2]);
}
}
bool c = true;
if (nxor[0] && line[N-1] != line[1]) {
c = false;
}
if (!nxor[0] && line[N-1] == line[1]) {
c = false;
}
if (!line[N-1] && nxor[N-1] && line[N-2] != line[0]) {
c = false;
}
if (!line[N-1] && !nxor[N-1] && line[N-2] == line[0]) {
c = false;
}
if (line[N-1] && nxor[N-1] && line[N-2] == line[0]) {
c = false;
}
if (line[N-1] && !nxor[N-1] && line[N-2] != line[0]) {
c = false;
}
 
if (c) {
for(int i = 0; i < N; i++) {
cout << (!line[i] ? 'S' : 'W');
}
cout << endl;
return 0;
}
c = true;
 
line[0] = 0;
line[1] = -1;
for (int i = 2; i < N; i++) {
if (line[i-1] == 0) {
line[i] = (nxor[i-1] ? line[i-2] : ~line[i-2]);
}
else {
line[i] = (nxor[i-1] ? ~line[i-2] : line[i-2]);
}
}
if (nxor[0] && line[N-1] != line[1]) {
c = false;
}
if (!nxor[0] && line[N-1] == line[1]) {
c = false;
}
if (!line[N-1] && nxor[N-1] && line[N-2] != line[0]) {
c = false;
}
if (!line[N-1] && !nxor[N-1] && line[N-2] == line[0]) {
c = false;
}
if (line[N-1] && nxor[N-1] && line[N-2] == line[0]) {
c = false;
}
if (line[N-1] && !nxor[N-1] && line[N-2] != line[0]) {
c = false;
}
 
if (c) {
for(int i = 0; i < N; i++) {
cout << (!line[i] ? 'S' : 'W');
}
cout << endl;
return 0;
}
c = true;
 
line[0] = -1;
line[1] = 0;
for (int i = 2; i < N; i++) {
if (line[i-1] == 0) {
line[i] = (nxor[i-1] ? line[i-2] : ~line[i-2]);
}
else {
line[i] = (nxor[i-1] ? ~line[i-2] : line[i-2]);
}
}
 
if (nxor[0] && line[N-1] == line[1]) {
c = false;
}
if (!nxor[0] && line[N-1] != line[1]) {
c = false;
}
if (!line[N-1] && nxor[N-1] && line[N-2] != line[0]) {
c = false;
}
if (!line[N-1] && !nxor[N-1] && line[N-2] == line[0]) {
c = false;
}
if (line[N-1] && nxor[N-1] && line[N-2] == line[0]) {
c = false;
}
if (line[N-1] && !nxor[N-1] && line[N-2] != line[0]) {
c = false;
}
 
if (c) {
for(int i = 0; i < N; i++) {
cout << (!line[i] ? 'S' : 'W');
}
cout << endl;
return 0;
}
c = true;
 
line[0] = -1;
line[1] = -1;
for (int i = 2; i < N; i++) {
if (line[i-1] == 0) {
line[i] = (nxor[i-1] ? line[i-2] : ~line[i-2]);
}
else {
line[i] = (nxor[i-1] ? ~line[i-2] : line[i-2]);
}
}
 
if (nxor[0] && line[N-1] == line[1]) {
c = false;
}
if (!nxor[0] && line[N-1] != line[1]) {
c = false;
}
if (!line[N-1] && nxor[N-1] && line[N-2] != line[0]) {
c = false;
}
if (!line[N-1] && !nxor[N-1] && line[N-2] == line[0]) {
c = false;
}
if (line[N-1] && nxor[N-1] && line[N-2] == line[0]) {
c = false;
}
if (line[N-1] && !nxor[N-1] && line[N-2] != line[0]) {
c = false;
}
 
if (c) {
for(int i = 0; i < N; i++) {
cout << (!line[i] ? 'S' : 'W');
}
cout << endl;
return 0;
}
c = true;
 
cout << -1 << endl;
return 0;
 
}