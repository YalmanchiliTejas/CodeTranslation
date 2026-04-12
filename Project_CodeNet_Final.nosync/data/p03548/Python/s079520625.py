x, y, z = map(int, input().split())
ans = 0
t = z
while True:
    if x >= (t + y + z):
        t += y + z
        ans += 1
    else:
        break
print(ans)