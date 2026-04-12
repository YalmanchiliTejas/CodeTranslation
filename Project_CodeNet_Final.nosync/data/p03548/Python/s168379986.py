x, y, z = map(int, input().split())
count = z
p = 0
ite = 1
while count < x:
    if ite % 2 == 0:
        if count + y > x:
            break
        else:
            count += y
            p += 1
            ite += 1
    elif ite % 2 != 0:
        if count + z > x:
            break
        else:
            count += z
            ite += 1

print(p)
