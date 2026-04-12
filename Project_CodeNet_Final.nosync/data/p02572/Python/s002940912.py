N = int(input())
A = list(map(int, input().split())) + [0]
B = [0]*(N+1)

for i in range(N-1):
    B[N-i-1] = A[N-i-1]+B[N-i]
ans = 0
MOD = 10**9 + 7

for i in range(N-1):
    ans = (ans + A[i]*B[i+1])%MOD
        
print(ans)