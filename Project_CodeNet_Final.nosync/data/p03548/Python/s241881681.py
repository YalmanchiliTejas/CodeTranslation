x,y,z=map(int,input().split())

print(x//(y+z) if x%(y+z)>=z else x//(y+z)-1)
