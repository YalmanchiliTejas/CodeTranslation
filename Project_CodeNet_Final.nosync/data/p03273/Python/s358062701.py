H, W = map(int, input().split())
L = [list(input()) for j in range(H)]
res = []

for w in range(W):
    t = []
    for h in range(H):
        t.append((L[h][w]))
    
    if '#' not in t:
        for h in range(H):
            L[h][w] = ""
            
for l in L:
    if "#" not in l:
        pass
    else:
        res.append(l)

for i in res:
    result = ''
    for j in i:
        result += j
    print(result)