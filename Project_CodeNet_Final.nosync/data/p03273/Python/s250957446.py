h, w = map(int, input().split())
a = []
delrow = []
delcol = []
cnt = 0

for i in range(h):
    a.append(list(input()))

for i in range(h):
    for j in range(w):
        if a[i][j] != ".":
            break
        else:
            cnt += 1
        if cnt == w:
            delrow.append(i)
    cnt = 0

for i in range(w):
    for j in range(h):
        if a[j][i] != ".":
            break
        else:
            cnt += 1
        if cnt == h:
            delcol.append(i)
    cnt = 0

for i in delrow [::-1]: #行を削除
    del a[i]
for i in delcol [::-1]: #列を削除
    for j in range(len(a)):
        del a[j][i]

for i in range(len(a)):
    print(*a[i], sep="")