n,m = map(int,input().split())

a = [list(input()) for i in range(n)]

h = []
l = []
co = 0
for i in range(n):
    co = 0
    for j in range(m):
        if a[i][j] == "#":
            co = 1
    if co == 0:
        l.append(i)
for i in range(m):
    co = 0
    for j in range(n):
        if a[j][i] == "#":
            co = 1
    if co == 0:
        h.append(i)

for i in range(len(l)):
    a.pop(l.pop())

for i in range(len(h)):
    p = h.pop()
    for j in range(len(a)):
        a[j].pop(p)

for i in range(len(a)):
    print("".join(a[i]))