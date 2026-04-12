n = int(input())
a = list(map(int, input().split()))
zenbu = sum(a)
ans = 0

for i in range(n):
  ans += a[i]*(zenbu-a[i])
 
print(ans // 2 % 1000000007)