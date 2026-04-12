import collections
H, W = map(int, input().split())
S = [input() for _ in range(H)]

def dfs(sy, sx, gy, gx):
    q = collections.deque()
    q.append((sy, sx))
    dist = [[float("inf")] * W for _ in range(H)]
    dist[sy][sx] = 0
    dx = [(1, 0), (0, 1)]
    while len(q) != 0:
        h, w = q.popleft()
        d = dist[h][w]
        for x, y in dx:
            h2 = h + y
            w2 = w + x
            if h2 >= 0 and h2 < H and w2 >= 0 and w2 < W:
                if S[h2][w2] == "#" and dist[h2][w2] == float("inf"):
                    dist[h2][w2] = d+1
                    q.append((h2, w2))
    return dist[gy][gx]

count = dfs(0, 0, H-1, W-1)+1
count2 = 0
for h in range(H):
    for w in range(W):
        if S[h][w] == '#':
            count2 += 1
if count == count2:
    print('Possible')
else:
    print('Impossible')