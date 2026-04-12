h,w = [int(x) for x in input().split()]
a = []
for _ in range(h):
    tmp = list(input())
    if set(tmp) != set("."):
        a.append(tmp)

for i in range(w):
    save = False
    for y in range(len(a)):
        if a[y][i] == '#':
            save = True
            break
    if not save:
        for y in range(len(a)):
            a[y][i] = '0'

for x in a:
    print(*[z for z in x if z != '0'],sep="")