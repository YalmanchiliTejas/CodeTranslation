x, y, z = list(map(int, input().split()))
x -= z
cnt = 0
while x >= y + z:
    x = x - y - z
    cnt += 1
print(cnt)
