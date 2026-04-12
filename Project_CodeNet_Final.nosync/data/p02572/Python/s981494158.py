N = int(input())
A = list(map(int, input().split()))

MOD =  10**9 + 7

ans = 0

t = sum(A)

for a in A:
    t -= a
    
    ans = ans + a * t
    ans %= MOD
    
print(ans)
