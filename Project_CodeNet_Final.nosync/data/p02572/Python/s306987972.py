N = int(input())
x = list(map(int, input().split()))
s = sum(x) - x[0]
ans = 0

for i in range(N-1):
  ans = ans + x[i]*s
  s = s - x[i+1]
ans = ans % 1000000007
  
  
print(ans)
