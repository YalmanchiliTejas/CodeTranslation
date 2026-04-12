H, W = map(int,input().split())

s = [list(input()) for _ in range(H)]

sharp_count = 0

for h in range(H):
  sharp_count += s[h].count("#")

if sharp_count == H+W-1:
  print("Possible")
else:
  print("Impossible")