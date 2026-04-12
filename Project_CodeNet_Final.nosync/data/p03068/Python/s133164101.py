import sys

N = input()
S = input()
K = input()
result = ''
c = S[int(K)-1]
for target in S:
    if target == c:
        result += c
    else:
        result += '*'
print(result)