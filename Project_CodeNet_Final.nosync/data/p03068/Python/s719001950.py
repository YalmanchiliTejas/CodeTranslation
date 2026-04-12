N = int(input())
S = input()
K = int(input())

target = S[K-1]

res = ''
for s in S:
    if s != target:
        res += '*'
    else:
        res += s
print(res)