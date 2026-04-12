# 初期入力
import sys
input = sys.stdin.readline  #文字列では使わない
N = int(input())
A = list(map(int, input().split()))
mod =10**9 +7
sum_a =sum(A)
ans =0
for i in range(N-1):
    sum_a -=A[i]
    ans +=(A[i] *(sum_a)) %mod
ans %=mod        
print(ans)