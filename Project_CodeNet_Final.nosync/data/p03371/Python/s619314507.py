a,b,c,x,y = map(int,raw_input().split(" "))

ans = 10**1000

dat3 = [0, x*2,y*2]

for cc in dat3:
  aa = x - cc/2
  if aa < 0:aa = 0
  bb = y - cc/2
  if bb < 0:bb=0
  p = aa*a + bb*b + cc*c
  if p < ans:
    ans = p
print ans