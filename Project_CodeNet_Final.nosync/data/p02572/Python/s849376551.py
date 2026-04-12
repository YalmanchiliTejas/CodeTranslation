mod = 10**9+7
n = int(input())
a = list(map(int, input().split()))
a.sort()
ans = 0
for i in a:
    ans += i
ans = ans**2
for i in a:
    ans -= i**2
print((ans//2)%mod)