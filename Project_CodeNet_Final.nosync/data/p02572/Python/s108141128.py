n = int(input())
a = list(map(int,input().split()))
sum = 0
m = 10**9+7

for i in range(n):
  sum = sum+a[i]

#sum = sum%m
#sum = sum*sum
ans = 0
for i in range(n):
  ans = ans + sum*a[i]
  ans = ans - a[i]*a[i]
ans = ans//2%m

print(ans)