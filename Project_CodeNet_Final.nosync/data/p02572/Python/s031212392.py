N = int(input())
A = [int(x) for x in input().split()]
S = [0] * (N+1)      #累積和用のリスト
s = 0
CONST = 10**9+7

#前準備として累積和を計算
for i in range(N):
    S[i+1] = S[i] + A[i]

#積の総和を計算
for i in range(N-1):
    s += A[i] * ((S[N] - S[i+1]) % CONST)
    s %= CONST

print(s)