r,g,b=map(int,input().split())
card = int(str(r)+str(g)+str(b))
if((card % 4) == 0):
    print("YES")
else:
    print("NO")
