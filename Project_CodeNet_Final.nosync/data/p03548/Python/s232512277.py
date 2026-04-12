x, y, z = map(int, input().split())

l = 0
c = 0
while True:
    l += z
    if l >= x:
        break
    else:
        l += y
        if l+z > x:
            break
        else:
            c += 1

print(c)
