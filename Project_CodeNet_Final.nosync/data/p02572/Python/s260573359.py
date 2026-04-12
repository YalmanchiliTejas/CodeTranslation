N = int(input())
A = list(map(int, input().split()))

B = [0]*N

num = 0
for i in reversed(range(N)):
    B[i] = A[i] + num
    num = B[i]
    
ans = 0
for i in range(N-1):
    ans += A[i]*B[i+1] %1000000007

print(ans%1000000007)