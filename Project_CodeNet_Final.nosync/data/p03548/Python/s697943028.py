x, y, z = map(int,input().split())
x -= z
c = 0
while x-(y+z)>=0:
    x -= y+z
    c += 1
print(c)