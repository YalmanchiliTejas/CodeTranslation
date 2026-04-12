x, y, z = map(int, input().split())

s = z
cnt = 0
while True:
    s += y + z
    if s > x:
        break
    cnt += 1

print(cnt)
