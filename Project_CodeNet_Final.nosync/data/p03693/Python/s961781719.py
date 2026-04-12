r,g,b=map(int,input().split())
t=r*100+g*10+b

if t%4==0:
    print("YES")
else:
    print("NO")