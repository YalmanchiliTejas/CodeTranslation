H, W = list(map(int,input().split()))

D = []
f = [0] * W
for i in range(H):
    d = input()
    if d.count('.') == W:
        continue
    D.append(d)
    for j in range(W):
        if d[j] == '.':
            f[j] += 1

re = [''] * len(D)
for i in range(len(D)):
    str = D[i]
    for j in range(len(str)):
        if f[j] != len(D):
            re[i] += str[j]

for str in re:
    print(str)