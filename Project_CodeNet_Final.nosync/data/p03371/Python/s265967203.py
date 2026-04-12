a, b, c, x, y = map(int,input().split())

ans=float("inf")
for i in range(max(x, y) + 1):
    if i <= min(x, y):
        temp = a * (x - i) + b *(y - i) + c * 2 * i
        ans = min(temp, ans)
    else:
        if x > y:
            temp = a * (x - i) + c * 2 * i
        else:
            temp = b * (y - i) + c * 2 * i
            ans = min(ans, temp)
print(ans)