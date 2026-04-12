h, w = map(int, input().split())
a = []
for i in range(h):
    A = input()
    a.append(A)

b = []
for i in range(h):
    flag = 1
    for j in range(w):
        if a[i][j] == "#":
            flag = 0
    if not flag:
        b.append(a[i])

s = set()
for j in range(w):
    flag = 1
    for i in range(len(b)):
        if b[i][j] == "#":
            flag = 0
    if flag:
        s.add(j)

for i in b:
    c = ""
    for j in range(len(i)):
        if not j in s:
            c += i[j]
    print(c)
