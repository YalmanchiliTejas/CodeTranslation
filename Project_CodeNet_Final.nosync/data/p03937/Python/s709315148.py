H, W = map(int, input().split())
ans = 0
for _ in range(H):
    a = input()
    ans += a.count("#")
if ans == H+W-1:
    print("Possible")
else:
    print("Impossible")
