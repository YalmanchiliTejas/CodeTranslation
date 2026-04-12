N, K = map(int, input().split())
ans = 0
b = K+1
while b <= N:
  p = N//b
  r = N%b
  ans += p*max(0,b-K)+max(0, r-K+1)-(0 if K > 0 else 1)
  b += 1
print(ans)