x, y, z = map(int, input().split())

seat = x
ans = 0

seat -= z
while True:
    if seat - (y+z) >= 0:
        ans += 1
        seat -= (y+z)
    else:
        break
print(ans)