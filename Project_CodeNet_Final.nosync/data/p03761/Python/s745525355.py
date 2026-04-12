#!/usr/bin/env python3

n = int(input())
S = [ sorted(input()) for _ in range(n) ]

ans = ""

for i in S[0]:
    flag = True
    for j in range(n):
        if i not in S[j]:
            flag = False
            break

    if flag:
        ans += i
        for j in range(n):
            S[j] = S[j][0:S[j].index(i)] + S[j][S[j].index(i)+1:]

print(ans)
