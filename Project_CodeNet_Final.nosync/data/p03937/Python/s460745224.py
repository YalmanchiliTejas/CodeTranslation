H, W = map(int, input().split())
c = [input() for _ in range(H)]
dist = [[-1]*W for _ in range(H)]

now = 0
for h in range(H):
    now = min(now,W-1)
    if c[h][now]!="#":
        print("Impossible")
        exit()
    for w in range(now,W):
        if c[h][w]==".":
            now-=1
            break
        else:
            dist[h][w]=0
            now+=1

for h in range(H):
    for w in range(W):
        if c[h][w]=="#" and dist[h][w]==-1:
            print("Impossible")
            exit()

if c[H-1][W-1]=="#":
    print("Possible")
else:
    print("Impossible")