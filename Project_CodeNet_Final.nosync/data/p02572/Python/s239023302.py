N = int(input())
A = list(map(int,input().split()))
B = [0] * (N+1)

# 累積和を使う
for i in range(1,N+1):
    B[i] = A[i-1]+B[i-1]
# 累積和の配列完成
# print(B) 

ans = 0
MOD = 10**9+7
for i in range(N):
    ans += A[i] * (B[N] - B[i+1])
    ans %= MOD
print(ans)