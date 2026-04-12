x, y, z = map(int, input().split())
ans = 0
while x >= ans * y + (ans + 1) * z:
    ans += 1

print(ans - 1)