x,y,z = map(int,input().split())
x -= 2 * z
count = 0
while x >= y:
    x -= (y+z)
    count += 1
else:
    print(count)