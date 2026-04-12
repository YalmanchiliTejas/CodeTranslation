h, w = map(int, input().split())
a = [list(input()) for _ in [0] * h]

x = []
y = []
for i in range(h):
    if "#" in a[i]:
        y += [i]
for i in range(w):
    t = []
    for j in range(h):
        t.append(a[j][i])
    if "#" in t:
        x += [i]

for i in y:
    for j in x:
        print(a[i][j], end="")
    print()
