n = int(input())
a = list(map(int,input().split()))
wa = sum(a)
ans = 0
for i in range(n):
    other = wa-a[i]
    ans += other*a[i]
ans = (ans//2)%(10**9+7)

print(ans)