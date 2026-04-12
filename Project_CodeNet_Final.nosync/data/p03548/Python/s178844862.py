x, y, z = map(int, input().split())
tmp = x - y - z - z
ans = 1 if tmp >= 0 else 0

while True:
    if tmp < y + z:
        break
    tmp = tmp - y - z
    ans += 1

print(ans)