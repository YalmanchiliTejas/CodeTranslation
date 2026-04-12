n = int(input())
a = list(map(int,input().split()))
mod = 10**9 + 7
suma = sum(a)
ans = 0
for i in a:
    suma -= i
    ans += i * suma
    ans %= mod
print(ans)