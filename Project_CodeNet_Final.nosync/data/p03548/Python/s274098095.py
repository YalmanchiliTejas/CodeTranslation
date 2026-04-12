X, Y, Z = map(int, input().split())
X -= Z 
ans = 0
 
while True:
  X -= (Y + Z)
  if X < 0:
    break
  else:
    ans += 1
    
print(ans)