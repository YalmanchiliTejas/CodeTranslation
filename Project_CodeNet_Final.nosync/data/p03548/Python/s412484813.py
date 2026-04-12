# y*n + z*(n+1) <= x
# (y+z)*n <= x-z
# n <= (x-z)/(y+z)
x,y,z = map(int,input().split())
print((x-z)//(y+z))