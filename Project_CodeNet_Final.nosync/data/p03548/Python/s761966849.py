x, y, z = map(int, input().split())
ans = 0
now = z
while True:
    now += y + z
    ans += 1
    if now + y + z > x:
        break
print(ans)
