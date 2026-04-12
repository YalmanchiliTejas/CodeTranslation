x,y,z=map(int,input().split())
x-=z
print((x-x%(y+z))//(y+z))