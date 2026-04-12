n, x = map(int, input().split())
ans = 0
for i in range(n+1):
    if x > 2 ** (n + 1 - i) - 1:
        x -= 2 ** (n + 1 - i) - 1
        ans += 2 ** (n - i)
    elif x == 2 ** (n + 1 - i) - 1:
        ans += 2 ** (n - i)
        break
    elif x == 2 ** (n + 1 - i) - 2:
        ans += 2 ** (n - i) - 1
        break
    else:
        x -= 1
print(ans)