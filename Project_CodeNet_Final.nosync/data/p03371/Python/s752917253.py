A,B,C,X,Y = map(int,input().split())
ans = float('inf')
for ci in range(max(2*X+1,2*Y+1)):
  val = ci*C +max(0,(X-ci//2)*A) + max(0,(Y-ci//2)*B)
  ans = min(val, ans)
print(ans)