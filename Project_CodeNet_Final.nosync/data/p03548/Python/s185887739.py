x,y,z = map(int,input().split())
a = int(x/(y+z))
b = x%(y+z)

if b < z:
    print(a-1)
else:
    print(a)
