h, w = map(int, input().split())
a = [input() for _ in range(h)]
L = [1] * w
for i in range(w):
    if a[0][i] == '.':
        for j in range(h):
            if a[j][i] == '#':
                break
        else:
            L[i] = 0
for k in range(h):
    if '#' in a[k]:
        L2 = []
        for l in range(w):
            if L[l] == 1:
                L2.append(a[k][l])
        print(*L2, sep='')
