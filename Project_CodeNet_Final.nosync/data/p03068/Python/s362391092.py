N = int(input())
S = input()
K = int(input())


tgt = S[K-1]
res = []
for c in S:
    if c == tgt:
        res.append(c)
    else :
        res.append('*')
print(''.join(res))