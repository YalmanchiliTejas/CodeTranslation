H, W = map(int, input().split())

a = [input() for w in range(H)]

for i in range(H)[::-1]:
    if '#' not in a[i]:
        del a[i]
        H -= 1

n = []

for j in range(W)[::-1]:
    m = [''.join([t[j] for t in a])]
    if '#' in m[0]:
        n += m

for k in range(H):
    print(''.join(u[k] for u in n[::-1]))