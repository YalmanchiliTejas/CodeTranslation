x, y, z = map(int, input().split())
cnt = 0
for i in range(1, x):
    if (i+1) * z + i * y <= x:
        cnt += 1
    else:
        break
print(cnt)
