x, y, z = input().split()
x = int(x)
y = int(y)
z = int(z)

cnt = 0
rest = x

while(True):
    if(rest - (y + z) >= z):
        x -= y + z
        cnt += 1
        rest -= (y + z)
    else:
        break


print(cnt)