MOD = 1000000007
 
N = int(input())
A = list(map(int, input().split())) 
 
ans = 0
s = sum(A)
 
for a in A:
    s -= a
    ans += (a * s)

ans %= MOD

print(ans)