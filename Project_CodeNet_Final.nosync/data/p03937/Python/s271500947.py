H,W=map(int,input().split())
c=sum(input().count("#") for _ in [0]*H)
print("Possible" if c==H+W-1 else "Impossible")