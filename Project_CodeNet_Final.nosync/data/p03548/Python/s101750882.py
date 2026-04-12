x,y,z = (int(i) for i in input().split())
X,Y = x-z, y+z
print((X-X%Y)//Y)