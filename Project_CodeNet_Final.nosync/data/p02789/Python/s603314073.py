import sys
n, m = map(int, sys.stdin.readline().split())

if n <= m:
  ans = "Yes"
else:
  ans = "No"

print(ans)
