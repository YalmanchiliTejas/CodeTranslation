A, B, C, X, Y = map(int, input().split())
a = X
b = Y
c = 0
ans = a*A + b*B + c*C
while(a > 0 or b > 0):
  a = max(a-1, 0)
  b = max(b-1, 0)
  c += 2
  tmp = a*A + b*B + c*C
  if(tmp < ans):
    ans = tmp
  
print(ans)