H, W = map(int, input().split())
ah = [input() for _ in range(H)]

chs = {h for h in range(H) if all(a == '.' for a in ah[h])}
cws = {w for w in range(W) if all(a[w] == '.' for a in ah)}

for h in range(H):
    if h not in chs:
        print(''.join(ah[h][w] for w in range(W) if w not in cws))