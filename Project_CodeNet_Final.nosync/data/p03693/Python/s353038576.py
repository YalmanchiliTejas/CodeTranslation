r,g,b=map(int,input().split())

integer=100*r+10*g+b

if integer%4 == 0:
    print("YES")
else:
    print("NO")