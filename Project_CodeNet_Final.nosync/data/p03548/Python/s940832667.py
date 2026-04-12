x, y, z = map(int, input().split())

l = y + 2*z
ans = 0
while l <= x:
    l += y + z
    ans += 1

print(ans)
