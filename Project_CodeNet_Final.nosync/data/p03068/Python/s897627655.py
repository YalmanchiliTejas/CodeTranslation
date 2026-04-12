N = int(input())
S = input()
K = int(input())

tar = S[K - 1]

res = []
for s in S:
    if s != tar:
        res.append('*')
    else:
        res.append(tar)

print(''.join(res))
