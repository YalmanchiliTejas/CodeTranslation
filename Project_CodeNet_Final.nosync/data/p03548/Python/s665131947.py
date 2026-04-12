x,y,z = map(int, input().split())
cnt=0
if x>=y+2*z:
  cnt+=1
  x -= (y+2*z)
cnt += (x//(y+z))
print(cnt)