h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]
s = [set(), set()]
for i in range(h):
    f = True
    for j in range(w):
        f &= (a[i][j] == ".")
    if f:
        s[0].add(i)

for i in range(w):
    f = True
    for j in range(h):
        f &= (a[j][i] == ".")
    if f:
        s[1].add(i)

for i in range(h):
    if i in s[0]:
        continue
    for j in range(w):
        if j in s[1]:
            continue
        print(a[i][j], end="")
    print()
