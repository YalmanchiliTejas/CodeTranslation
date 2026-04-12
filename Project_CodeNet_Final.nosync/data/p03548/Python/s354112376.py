x,y,z = map(int,input().split())
p = y + z + z
c = 0

while p <= x:
    c += 1
    p = p + y + z

print(c)