# -*- coding: utf-8 -*-
N = int(input())
S = str(input())
K = int(input())

keep=S[K-1]
ans=""
for i in S:
    if i==keep:
        ans=ans+i
    else:
        ans=ans+"*"
print(ans)