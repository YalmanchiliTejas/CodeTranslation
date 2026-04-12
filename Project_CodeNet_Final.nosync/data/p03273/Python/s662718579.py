H,W = map(int,(input().split()))
a = [[] for _ in range(H)]
b = []
deh = []
for i in range(H):
    a[i] = list(input())
    
for i in range(H):
    if a[i] != ["."]*W:
        b.append(a[i])

for i in range(W)[::-1]:
    c = 0
    for j in range(len(b)):
        if b[j][i] == ".":
            c += 1
    if c == len(b):
        for j in range(len(b)):
            b[j].pop(i)

for i in range(len(b)):
    ans = "".join(b[i])
    print(ans)