'''
（公式解説参照）
A[i]*A[i+1]+A[i]*A[i+2]+…+A[i]*A[N]=A[i]*(A[i+1]+A[i+2]+…+A[N])
リストAに対する累積和を求めておく
'''
N = int(input())
A = list(map(int, input().split()))
MOD = 10 ** 9 + 7

# 累積和
total = []
total.append(A[0])
for i in range(1, N):
    total.append(total[i-1] + A[i])
# print(total)

# iの値について全探索
ans = 0
for i in range(N):
    tmp = (total[-1] - total[i])
    ans += A[i] * tmp
    ans %= MOD

print(ans)
