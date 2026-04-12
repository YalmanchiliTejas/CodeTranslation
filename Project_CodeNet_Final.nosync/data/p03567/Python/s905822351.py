# -*- coding: utf-8 -*-

S = input()

ans = False
for i in range(len(S) - 1):
    if S[i] == 'A' and S[i + 1] == 'C':
        ans = True
        break

print('Yes' if ans else 'No')
