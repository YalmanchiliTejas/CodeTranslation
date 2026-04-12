N = int(input())
A = list(map(int, input().split()))

ans = 0
s = 0

mod = 10**9 + 7

def add(a, b):
    return (a + b) % mod

def mul(a, b):
    return ((a % mod) * (b % mod)) % mod

for i in reversed(range(N-1)):
    s = add(s, A[i+1])
    ans = add(ans, mul(A[i], s)) 
    
print(ans)
