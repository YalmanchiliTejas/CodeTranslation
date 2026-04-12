# -*- coding: utf-8 -*-
n = int(input())
a = []
for i in range(n):
    a.append(str(input()))

alph = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
count = [[0 for _ in range(len(alph))] for _ in range(n)]
for i in range(n):
    for j in range(len(alph)):
        count[i][j] = a[i].count(alph[j])
#print(count)
tmp = [100 for _ in range(len(alph))]
for i in range(len(alph)):
    for j in range(n):
        if count[j][i] < tmp[i]:
            tmp[i] = count[j][i]
ans = ''
for i in range(len(alph)):
    ans += alph[i] * tmp[i]
print(ans)
