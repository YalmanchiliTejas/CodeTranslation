x, y, z = map(int,input().split())
x -= z
ans = 0

while x > 0:
    ans += 1
    x -= y
    x -= z
    if x < 0:
        ans -= 1

print(ans)
