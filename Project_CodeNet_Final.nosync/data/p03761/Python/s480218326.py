# -*- coding: utf-8 -*-

n = int(input())
dic = {}
for i in range(n):
    s = list(input())
    for j in range(97, 123):
        if i == 0:
            dic[chr(j)] = s.count(chr(j))
        else:
            dic[chr(j)] = min(dic[chr(j)], s.count(chr(j)))
ans = []
for key in dic:
    if dic[key] != 0:
        for _ in range(dic[key]):
            ans.append(key)
ans.sort()
print(''.join(ans))
