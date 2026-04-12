x,y,z = map(int,input().split())
p = x//(y+z)
if((y+z)*p + z <= x):
    print(p)
else:
    print(p-1)