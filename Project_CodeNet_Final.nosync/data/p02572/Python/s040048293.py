n = int(input())
a = list(map(int,input().split()))
s = [a[0]]
sums = sum(a)
for i in range(1,n):
  s.append(s[i-1]+a[i])
ans = 0
for i in range(n-1):
  ans += a[i] * (sums - s[i])
b = 10**9 + 7
print(ans%b)