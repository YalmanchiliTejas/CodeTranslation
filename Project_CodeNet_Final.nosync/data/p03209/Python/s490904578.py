n, x = map(int, input().split())

l = [0] * (n + 1)
p = [0] * (n + 1)
l[0] = 1
p[0] = 1
for i in range(n):
    l[i+1] = l[i]*2+3
    p[i+1] = p[i]*2+1

ans = 0
for i in range(n, -1, -1):
    layer = l[i]
    if x >= layer:
        ans += p[i]
        break
    elif x <= 1:
        break

    half = l[i - 1] + 1
    if x > half:
        ans += 1
        ans += p[i - 1]
        x -= half
        x -= 1
    elif x <= half:
        x -= 1

print(ans)
