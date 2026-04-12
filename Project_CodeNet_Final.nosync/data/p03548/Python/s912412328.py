x, y, z = map(int, input().split())
cnt = 0
while x >= 0:
    x -= z
    if x >= y+z:
        x -= y
        cnt += 1

print(cnt)