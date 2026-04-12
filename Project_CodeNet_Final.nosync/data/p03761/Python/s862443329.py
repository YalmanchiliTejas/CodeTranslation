# coding: utf-8
n = int(input())
data = [input() for i in range(n)]
txt = [2501] * 26
for i in range(n):
    for j in range(26):
        txt[j] = min(txt[j], data[i].count(chr(97 + j)))

for i in range(26):
    print(chr(97 + i) * txt[i], end='')
print()
