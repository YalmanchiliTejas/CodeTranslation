# -*- coding: utf-8 -*-

N = int(input())
S = input()
K = int(input())

k_chr = S[K-1]
output = ''

for char in S:
    if char == k_chr:
        output += k_chr
    else:
        output += '*'

print (output)