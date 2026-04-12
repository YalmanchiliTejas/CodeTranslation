r,g,b=map(int, input().split())
rgb=str(r)+str(g)+str(b)
print("YES" if int(rgb)%4==0 else "NO")
