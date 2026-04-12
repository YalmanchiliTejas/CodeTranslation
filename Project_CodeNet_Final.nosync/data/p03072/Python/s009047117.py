# 初期入力
import sys
input = sys.stdin.readline
N = int(input())
H = list(map(int, input().split()))
ans =0
for i in range(1,N):
    if max(H[:i+1]) ==H[i] :
        ans +=1
 
print(ans+1)