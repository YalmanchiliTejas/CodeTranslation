def inpl(): return list(map(int, input().split()))

H, W = inpl()
A = []
for _ in range(H):
    A.append([x=="#" for x in input()] + [False])

A.append([False] * (W+1))

Q = [[0, 0]]
visited = [[False]*(W+1) for _ in range(H+1)]
visited[0][0] = True

while Q:
    h, w = Q.pop()
    for dh, dw in [[0, 1], [1, 0]]:
        nh, nw = h+dh, w+dw
        if A[nh][nw] and not visited[nh][nw]:
            visited[nh][nw] = True
            Q.append([nh, nw])

plength = sum([sum(a) for a in A])

if plength == (H+W-1) and visited[H-1][W-1]:
    print("Possible")
else:
    print("Impossible")