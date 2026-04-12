n, k = map(int, input().split())
if k==0:
  print(n**2)
else:
  ans = 0
  for i in range(k+1, n+1):
    t = (n+1)//i
    ans += t*(i-k) + max(0, (n-(t*i+k)+1))
  print(ans)