n = int(input())
a = list(map(int,input().split()))

MOD = 10 ** 9 + 7
s =sum(a) % MOD
ans = 0

for i in a :
    s -= i
    s %= MOD
    ans += i * s
    ans %= MOD
    
print(ans)