h, w = map(int, input().split())
a = []
delcol = []
cnt = 0

for i in range(h):
    b = list(input())
    if set(b) == {"."}:
            continue
    a.append(b)

for i in range(w):
    for j in range(len(a)):
        if a[j][i] != ".":
            break
        else:
            cnt += 1
        if cnt == len(a):
            delcol.append(i)
    cnt = 0

for i in delcol [::-1]: #列を削除
    for j in range(len(a)):
        del a[j][i]

for i in range(len(a)):
    print(*a[i], sep="")