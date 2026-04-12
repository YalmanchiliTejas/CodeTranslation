n = int(input())

ans = 0
for i in range(1, n+1):
    ans += 800
    if i % 15 == 0:
        ans -= 200

print(ans)