x,y,z=map(int,input().split())
a=x//(y+z)
print(a-1 if a*(y+z)+z>x else a)