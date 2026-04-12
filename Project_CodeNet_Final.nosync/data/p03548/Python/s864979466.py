x,y,z=map(int,input().split())
w=y+z
print(x//w if x%w>=z else x//w-1)