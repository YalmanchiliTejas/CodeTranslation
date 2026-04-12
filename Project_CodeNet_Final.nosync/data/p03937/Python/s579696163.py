H,W = map(int, input().split())
A = [input() for _ in range(H)]

cnt = 0
for a in A:
    cnt += a.count("#")
print("Possible" if cnt == W + (H-1) else "Impossible")