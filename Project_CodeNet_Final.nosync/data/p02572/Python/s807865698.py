N = int(input())
A = list(map(int,input().split()))
Ans = 0
S = sum(A)

for i in range(N-1):
    S -= A[N-i-1]
    Ans += A[N-i-1]*S

print(Ans%((10**9)+7))