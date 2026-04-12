def INT():
    return int(input())

def MI():
    return map(int, input().split())

def LI():
    return list(map(int, input().split()))

N = INT()
A = LI()
mod = 10**9 + 7
sm = sum(A) - A[0]
ans = 0

for i in range(N - 1):
    ans += A[i] * sm
    ans %= mod
    sm -= A[i + 1]
    
print(ans)