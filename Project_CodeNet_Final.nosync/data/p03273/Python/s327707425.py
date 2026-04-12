h, w = map(int, input().split())
l = []

for i in range(h-1, -1, -1):
    s = list(input())
    if s!=["."]*w:
        l.append(s)

for j in range(w-1, -1, -1):
    cnt = 0
    for k in range(len(l)):
        if l[k][j]==".":
            cnt += 1
    if cnt ==len(l):
        for k in range(len(l)):
            l[k].pop(j)

for i in range(len(l)):
    print("".join(l[i]))