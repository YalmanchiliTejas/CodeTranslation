x, y, z = map(int, input().split())

cnt = 0
cm = z
while (cm < x):
    cm += y
    if (cm+z) > x:
        break
    elif (cm+z)<=x:
        cm += z
        cnt += 1
print(cnt)