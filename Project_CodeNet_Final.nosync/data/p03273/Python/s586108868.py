h, w = map(int, input().split())
field = []
hstack, wstack = set(), set()

for i in range(h):
    a = input()
    field.append(a)
    for j in range(w):
        if a[j] == '#':
            hstack.add(i)
            wstack.add(j)

hstack = sorted(list(hstack))
wstack = sorted(list(wstack))

for i in hstack:
    out = ""
    for j in wstack:
        out += field[i][j]
    print(out)