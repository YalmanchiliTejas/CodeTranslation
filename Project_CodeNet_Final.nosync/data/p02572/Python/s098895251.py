n = int(input())
a = list(map(int, input().split()))
ans = 0
r = sum(a)
for i in a[:n-1]:
    r = r - i
    ans = (ans+i*r)%(10**9+7)
print(ans)