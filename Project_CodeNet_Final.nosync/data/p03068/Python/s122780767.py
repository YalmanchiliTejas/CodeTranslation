N = int(input())
S = input()
K = int(input())
res = ''

for i in S:
    if i != S[K-1]:
        res += '*'
    else:
        res += i

print(res)