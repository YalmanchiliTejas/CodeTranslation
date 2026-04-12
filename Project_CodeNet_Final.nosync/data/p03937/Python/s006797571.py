H, W = map(int, input().split())
cnt = sum([input().count("#") for _ in range(H)])
print("Possible" if cnt == H+W-1 else "Impossible")