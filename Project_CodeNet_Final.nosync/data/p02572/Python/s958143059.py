n = int(input())

ls = list(map(int,input().split()))
mod = 10**9+7
acc = [0]

for a in ls:
  acc.append(acc[-1]+a)
  
ans = 0

for i in range(len(ls)-1):
  ans += ls[-i-1]*acc[-i-2]
  ans %= mod


print(ans)