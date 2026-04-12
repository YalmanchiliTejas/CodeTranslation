n = int(input())
a = list(map(int, input().split()))

ans = 0
while any(a[i] >= n for i in range(n)):
    res = [-(-(a[i] - n + 1) // n) for i in range(n)]
    x = sum(res)
    a = [a[i] + x - (n + 1) * res[i] for i in range(n)]
    ans += x
    #print(ans)

print(ans)