n = int(input())
A = [int(i) for i in input().split()]
cum_sum = [0]
ans,sum = 0,0

# 累積和を求める
for i in range(len(A)):
    cum_sum.append(cum_sum[i]+A[i])

for i in range(n):
    # A[i+1]+A[i+2]+...+A[n]を累積和で求める
    sum = (cum_sum[n]-cum_sum[i+1])%1000000007
    # A[i]*(A[i+1]+A[i+2]+...+A[n])の処理
    # なおA[i+1]=A[j],A[i+2]=A[j+2]...である
    ans += A[i]*sum
    # 1000000007で割る
    ans %= 1000000007   
print(ans)