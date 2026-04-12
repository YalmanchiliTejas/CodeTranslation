h,w = map(int,input().split())
a = [[] for i in range(0,h)]
for i in range(0,h):
    A = list(input())
    a[i].extend(A)

hlist = []
for i in range(0,h):
    for j in range(1,w):
        if a[i][j-1] !=  a[i][j]:
            break
        if j == w-1 and a[i][j] == ".":
            hlist.append(i)
wlist = []
for j in range(0,w):
    for i in range(1,h):
        if a[i-1][j] !=  a[i][j]:
            break
        if i == h-1 and a[i][j] == ".":
            wlist.append(j)

b = 0
for i in hlist:
    a.pop(i-b)
    b += 1
    h -= 1
b = 0
for j in wlist:
    for i in range(0,h):
        a[i].pop(j-b)
    b += 1
    w -= 1

for i in range(0,h):
    for j in range(0,w):
        if j < w-1:
            print(a[i][j],end="")
        else:
            print(a[i][j])
