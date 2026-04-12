list = input().split()
x,y,z = int(list[0]),int(list[1]),int(list[2])
x -= z * 2
num = x % (y+z)
if num >= y:
    print((x//(y+z))+1)
else:
    print(x//(y+z))
