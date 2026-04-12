r,g,b=map(int,input().split())
A=(r*100+g*10+b)%4
if A==0:
    print("YES")
else:
    print("NO")