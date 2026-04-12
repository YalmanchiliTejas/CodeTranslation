x,y,z = map(int,input().split())
y %= 4
if y == 0:
    if z % 4 ==0:
        print("YES")
        exit()
if y == 1:
    if z % 4 == 2:
        print("YES")
        exit()
if y == 2:
    if z % 4 == 0:
        print("YES")
        exit()
if y == 3:
    if z % 4 == 2:
        print("YES")
        exit()
print("NO")