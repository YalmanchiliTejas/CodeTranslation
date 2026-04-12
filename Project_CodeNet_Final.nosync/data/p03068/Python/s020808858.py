N = int(input())
S = input()
K = int(input())

p = S[K-1]
result = ''
for s in S:
    if s == p:
        result += s
    else:
        result += '*'

print(result)