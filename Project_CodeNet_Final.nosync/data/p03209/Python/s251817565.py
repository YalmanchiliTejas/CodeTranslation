n,x = map(int,input().split())

piece = [1]
meet  = [1]
for _ in range(n):
  piece.append(piece[-1]*2 +3)
  meet.append(meet[-1]*2+1)
  
ans = 0
i = n
while x:
  if x > (piece[i]+1)//2:
    ans += meet[i]//2+1
    x -= piece[i]//2+1
    i -= 1
  elif x== (piece[i]+1) //2:
    ans += meet[i]//2+1
    x = 0
  else:
    i -= 1
    x -= 1
print(ans)