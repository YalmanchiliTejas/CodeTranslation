#! /usr/bin/env python3
# -*- coding: utf-8 -*-
N = int(input())
S = list(input())
K = int(input())
a = S[K-1]
ans = []
for k in S:
    if k != a:
        ans.append("*")
    else:
        ans.append(k)

answer = "".join(ans)
print(answer)