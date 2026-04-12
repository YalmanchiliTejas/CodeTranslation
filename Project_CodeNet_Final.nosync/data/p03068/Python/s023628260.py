# -*- coding: utf-8 -*-
n = int(input())
s = str(input())
k = int(input())
"""
n = 7
s = "djfsfok"
k = 3
"""
index_num = [n for n, v in enumerate(s) if v == s[k-1]]
ans = list("*"*n)
index_num = list(index_num)
for i in range(0, len(index_num)):
    ans[index_num[i]] = s[k-1]
print("".join(ans))