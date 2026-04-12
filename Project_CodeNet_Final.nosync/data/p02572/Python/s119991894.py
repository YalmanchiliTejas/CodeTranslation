from itertools import accumulate

n = int(input())
A = list(map(int, input().split()))
rem = 10**9+7

acum = list(accumulate(A))

ans = 0
for i in range(n-1):
    ans += (A[i] * (acum[-1] - acum[i]))%rem
    ans  %=  rem
print(ans)