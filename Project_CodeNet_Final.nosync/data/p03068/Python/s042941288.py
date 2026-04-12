# -*- coding: utf-8 -*-

#----------
N = int(input().strip())
S = input().strip()
K = int(input().strip())
#----------
new_S=""
for word in S:
    if word != S[K-1]:
        new_S += "*"
    else:
        new_S += word

print(new_S)
