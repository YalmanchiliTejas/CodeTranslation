H,W=map(int,input().split())
gy,gx=H-1,W-1
grid=["" for i in range(H)]
touched=0
for i in range(H):
  grid[i]=input()
  touched+=grid[i].count("#")

print(("Imp","P")[touched==H+W-1]+"ossible")
