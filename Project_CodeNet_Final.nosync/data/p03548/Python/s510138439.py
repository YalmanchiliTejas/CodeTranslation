x,y,z = map(int, input().split())

ans = 0
remain = x - z
while True:
  if remain < y+z:
    break
  remain -= y+z
  ans +=1
print(ans)