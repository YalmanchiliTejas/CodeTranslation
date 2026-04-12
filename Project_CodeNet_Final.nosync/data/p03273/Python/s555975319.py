H, W = map(int, input().split())
m = []
for i in range(H):
    r = list(input())
    if r == ['.'] * W:continue
    m.append(r)

k = []
for i in range(W):
    if [m[j][i] for j in range(len(m))] == ['.'] * len(m):
        k.append(i)

ans = []    
for r in m:
    t = []
    for i,l in enumerate(r):
        if  not i in k:
            t.append(l)
    ans.append(t)
for l in ans:
    print(''.join(l))