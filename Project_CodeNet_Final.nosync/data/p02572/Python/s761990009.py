N = int(input())
l = list(map(int,input().split()))
Sum = sum(l)
ans = 0
for i in range(N-1):
    Sum -= l[i]
    ans += Sum*(l[i])
    ans %= (10**9 + 7)

print(ans)
