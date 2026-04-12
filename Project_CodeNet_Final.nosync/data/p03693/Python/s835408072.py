r,g,b=input().split()
g=int(g)
b=int(b)
H=g*10+b

if H % 4==0:
    print("YES")
else:
    print("NO")