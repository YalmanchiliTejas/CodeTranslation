H, W = map(int, input().split())
a = [input() for _ in range(H)]

b = []

for i in a:
    if i != '.' * W:
        b.append(i)

h = len(b)

ans = [[] for _ in range(h)]
        
for i in range(W):
    jdg = True
    for j in range(h):
        if b[j][i] != '.':jdg = False
        ans[j].append(b[j][i])
    if jdg:
        for j in range(h):
            ans[j].pop()

for a in ans:
    print(*a, sep='')
