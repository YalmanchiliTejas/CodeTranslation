H, W = map(int, input().split())
A = [input() for i in range(H)]
count = 0
for i in range(H):
    for j in range(W):
        if A[i][j] == "#":
            count +=1

queue = [(0, 0, 1)]
depth = 0
while queue:
    q = queue.pop(0)
    depth = max(depth, q[2])
    if A[q[0]][q[1]] == ".":
        continue
    if (q[0], q[1]) == (H-1, W-1):
        break
    if(q[0]+1 < H):
        queue.append((q[0]+1, q[1], q[2]+1))
    if(q[1]+1 < W):
        queue.append((q[0], q[1]+1, q[2]+1))

print("Possible" if depth==count else "Impossible")
        