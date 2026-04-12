n,x,m = map(int,input().split())
appeared=[False]*(m+1)
appeared[x]=True
ans = [0]
ANS = 0
div = x
DIV=[]
llen = 0
cnt = 0
while cnt < n:
  if div == 0:
    break
  cnt += 1
  ANS += div
  DIV.append(div)
  ans.append(ANS)
  llen += 1
  appeared[div] = True
  if appeared[div**2%m]:
    PPP=DIV.index(div**2%m)
    ANS = (ANS-ans[PPP])*((n-PPP)//(llen-PPP))
    rem = (n-PPP)%(llen-PPP)
    ANS+=ans[rem+PPP]
    break
  div **= 2
  div %= m
  
print(ANS)
