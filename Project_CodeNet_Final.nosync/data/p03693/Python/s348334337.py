r,g,b = list(map(int,input().split()))
z=100*r+10*g+b

if z%4==0:
    print("YES")
else:
    print("NO")
