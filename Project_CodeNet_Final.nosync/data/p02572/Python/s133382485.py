count = int(input())
a = list(map(int, input().split()))
mod = 10**9 + 7
ans = 0
sum = sum(a)

for i in range(count):
  sum = sum - a[i]
  ans += sum * a[i]
  
answer = ans % mod
print(answer)


  