h, w = map(int, input().split())
a = [[c for c in input()] for i in range(h)]

ah, aw = [0] * h, [0] * w
for i in range(h):
    for j in range(w):
        if a[i][j] == '#':
            ah[i] = aw[j] = True
ans = ''
for i in range(h):
    for j in range(w):
        if ah[i] and aw[j]:
            ans += a[i][j]
    if ah[i]:
        ans += '\n'
print(ans)
