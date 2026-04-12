x,y,z=map(int,input().split())
print(x//(y+z)) if x%(y+z)>=z else print(x//(y+z)-1)
