h,w = map(int,input().split())
row = [False] * h
col = [False] * w
a = []
for i in range(h):
    a.append(input())

for i in range(h):
    for x in range(w):
        if a[i][x] == '#':
            row[i] = True
            col[x] = True
for i in range(h):
    if row[i]:
        for x in range(w):
            if col[x]:
                print(a[i][x],end='')
        print()
