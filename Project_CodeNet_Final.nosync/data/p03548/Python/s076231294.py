x, y, z = map(int, input().split())
ans = 0
space = z
while space <= x:
    ans += 1
    space += y+z
if space > x:
    ans -= 1
print(ans)
