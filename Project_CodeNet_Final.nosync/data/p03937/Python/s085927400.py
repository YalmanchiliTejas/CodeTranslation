H, W = map(int, input().split())

shortest = (H-1) + (W-1)
tmp = -1
for i in range(H):
    tmp += input().count("#")

print("Possible" if tmp == shortest else "Impossible")
