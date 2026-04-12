H,W=map(int,input().split())
A=[input() for _ in range(H)]

Flag=True
x,y=0,0
for _ in range(H+W-2):
    if x+1 < H and A[x+1][y] == '#':
        x += 1
        continue
    if y+1 < W and A[x][y+1] == '#':
        y += 1
        continue
    Flag=False
    
Flag= Flag and (sum(x.count("#") for x in A)==H+W-1)
if Flag:
    print("Possible")
else:
    print("Impossible")
    

        
