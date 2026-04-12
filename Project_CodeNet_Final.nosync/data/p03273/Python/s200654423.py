h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]
r = ['.'] * w

for i in range(h-1, -1, -1):
    if a[i] == r:
        del(a[i])

h = len(a)
for i in range(w-1, -1, -1):
    allw = True
    for j in range(h):
        if a[j][i] != '.':
            allw = False
    if allw:
        for j in range(h):
            del(a[j][i])

for ai in a:
    print(''.join(ai))
