import sys
input = sys.stdin.readline
n = int(input().strip())
an = [int(input().strip()) for i in range(n)]
an.sort()

ans = an[-1] - an[0]
high = an[-1]
low = an[0]
c = n//2

if n % 2:
  for i in range(1,c):
    ans += high - an[i] + an[-i-1] - low
    high = an[-i-1]
    low = an[i]
  ans += max(high-an[c],an[c]-low)
  print(ans)
else:
  for i in range(1,c):
    ans += high - an[i] + an[-i-1] - low
    high = an[-i-1]
    low = an[i]
  print(ans)