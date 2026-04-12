H,W = list(map(int,input().split()))
a = [[c for c in input()] for _ in range(H)]

tmp = a.copy()
for i,row in enumerate(tmp[::-1],1):
    for c in row:
        if c == "#":
            break
    else:
        a.pop(H-i)
tmp = len(a)
for i in range(W-1,-1,-1):
    for j in range(tmp):
        if a[j][i] == "#":
            break
    else:
        for j in range(tmp):
            a[j].pop(i)

for row in a:
    print("".join(row))