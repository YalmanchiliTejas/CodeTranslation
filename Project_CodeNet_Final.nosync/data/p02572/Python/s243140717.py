n = int(input())
lst = list(map(int, input().split()))


MOD = 10 ** 9 + 7

rev = []

i = 0
for _ in range(n)[::-1]:
    i += lst[_]
    i %=  MOD
    rev.append(i)
    
lst= lst[0:n-1]
rev = rev[0:n-1]

ans = 0
for _ in range(n-1):
    ans += lst[_] * rev[n-(_+2)]
    ans %= MOD
    
print(ans)