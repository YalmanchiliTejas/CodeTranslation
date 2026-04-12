x, y, z = map(int, input().split())

cnt = 0
while True:
    if x < (y * (cnt + 1) + z * (cnt + 2)):
        break
    else:
        cnt += 1
print(cnt)