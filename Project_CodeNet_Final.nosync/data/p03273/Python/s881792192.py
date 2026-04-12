h, w = map(int,input().split())
a = [list(input()) for _ in range(h)]

yoko = []
for i in range(h):
    seta = set(a[i])
    if '#' in seta:
        yoko.append(a[i])

h = len(yoko)
w = len(yoko[0])
for i in range(w):
    tate = []
    for j in range(h):
        tate.append(yoko[j][i])
    settate = set(tate)
    if '#'not in settate:
        for j in range(h):
            yoko[j][i] = ''

ans = ''
for i in range(h):
    c = ''.join(yoko[i])
    ans += c
    if i != h-1:
        ans += '\n'
print(ans)