a, b, c, x, y = map(int, input().split())

ans = 5000 * 2 * (10**10)
for i in range((10 ** 5) + 1):
    check = 2*c*i + max(x-i,0)*a + max(y-i,0)*b
    if(ans > check):
        ans = check
print(ans)