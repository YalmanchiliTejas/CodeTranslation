x, y, z = map(int, input().split())
operator = True
count = 0

while operator:
    if (y+z)*count+z > x:
        operator = False
        break
    else:
        count += 1

print(count - 1)