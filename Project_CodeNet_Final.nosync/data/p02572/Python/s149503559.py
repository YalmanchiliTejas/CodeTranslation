N = int(input())
num_lis = list(map(int, input().split()))
ans = 0
p = 10**9+7
s = sum(num_lis)
num = 0
for i in range(N):
  num += num_lis[i]
  ans += ((s-num)*num_lis[i])%p
  
print(ans%p)