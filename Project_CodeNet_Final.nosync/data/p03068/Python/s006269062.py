# coding: utf-8

N = int(input())
S = input()
K = int(input())

kth_char = S[K-1]

output = ""
for c in S:
    if c != kth_char:
        output += "*"
    else:
        output += c

print(output)