h, w = map(int, input().split())
a = [list(input()) for i in range(h)]

for i in range(h-1,-1,-1):
    if not '#' in a[i]:
        del a[i]
h = len(a)
for j in range(w-1, -1, -1):
    res = True
    for i in range(h):
        if a[i][j] == '#':
            res = False
    if res:
        for i in range(h):
            del a[i][j]

for i in range(len(a)):
    print("".join(a[i]))

