[h,w] = [int(i) for i in input().split()]
a = []
t = 0
for i in range(h):
    tmp = input()
    if tmp != "." * w:
        a.append(tmp)
    else:
        t += 1
h -= t
ls = []
ans = []
for i in range(w):
    ls.append(i)
for i in range(w):
    intmp = 1
    for j in range(h):
        if a[j][i] == "#":
            intmp *= 0
    if intmp == 1:
        ls.pop(ls.index(i))
for i in range(h):
    tmp = ""
    for j in range(w):
        if j in ls:
            tmp += a[i][j]
    ans.append(tmp)

for i in range(h):
    print(ans[i])
