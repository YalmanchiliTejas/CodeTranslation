h, w = map(int, input().split())
a = [list(input()) for i in range(h)]

yoko = [1 for i in range(h)]
tate = [1 for i in range(w)]

for i in range(h):
    if a[i].count(".") == w:
        yoko[i] = 0

a_t = [list(x) for x in zip(*a)]

for i in range(w):
    if a_t[i].count(".") == h:
        tate[i] = 0

for i in range(h):
    s = ""
    for j in range(w):
        if yoko[i] and tate[j]:
            s += a[i][j]
    if s:
        print(s)