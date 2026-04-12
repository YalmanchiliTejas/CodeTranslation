n = int(input())
a = list(map(int, input().split()))

MOD = 10**9 + 7
s = 0
for i in a:s+=i

ans = 0
for i in a:
    ans += (((i*s)-(i*i)))
ans = ans//2
print(ans%MOD)