_ = int(input())
S = input()
K = int(input())

sc = S[K - 1]
ret = ''
for c in S:
    if c == sc:
        ret += c
    else:
        ret += '*'
print(ret)
