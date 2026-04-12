mod = 1000000007
n = int(input())
als = list(map(int, input().split()))

sumlist = [0 for _ in range(n)]
sumlist[0] = als[0]

for i in range(1, n-1):
    sumlist[i] = sumlist[i-1] + als[i]

ans = 0

for i in range(n-1):
    ans += als[n-1-i] * sumlist[n-2-i]
    ans = ans%mod

print(ans)