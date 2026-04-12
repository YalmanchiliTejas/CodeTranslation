# -*- coding: utf-8 -*-
from collections import Counter
from string import ascii_lowercase

N = int(input())
S = []
result = ""
abc = {a: 50 for a in list(ascii_lowercase)}

for n in range(N):
    S.append(Counter(str(input())))

for a in list(ascii_lowercase):
    for n in range(N):
        abc[a] = min(S[n][a], abc[a])

for a in list(ascii_lowercase):
    result += a * abc[a]

print(result)