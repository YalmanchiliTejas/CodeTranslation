r,g,b=map(int,input().split())
num=str(r)+str(g)+str(b)
num=int(num)
if num%4==0:
    print("YES")
else:
    print("NO")