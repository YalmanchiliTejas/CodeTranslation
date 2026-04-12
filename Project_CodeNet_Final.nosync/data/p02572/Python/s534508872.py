n = int(input())
a = list(map(int, input().split()))

ans = 0

for i in range(2,n+1):
  a[-i] += a[-i+1]

for i in range(len(a)-1):
  ans = ans % 1000000007 + ((a[i] - a[i+1]) * a[i+1]) % 1000000007
    
print(ans % 1000000007)