H, W = map(int,input().split())
t = 0
for k in range(H):
    t += input().count("#")
print("Possible" if t == H+W-1 else "Impossible")
