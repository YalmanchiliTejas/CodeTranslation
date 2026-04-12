
x,y,z = map(int,input().split())
ans = 1
while True:
  if ans*(y+z)+z>x:
    break
  else:
    ans += 1
print(ans-1)
