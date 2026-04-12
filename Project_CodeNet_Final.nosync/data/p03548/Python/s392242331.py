x, y, z = map(int, input().split())

ans = 0
l_sum = 0

while l_sum <= (x - z):
    ans += 1
    l_sum += y + z
print(ans - 1)
