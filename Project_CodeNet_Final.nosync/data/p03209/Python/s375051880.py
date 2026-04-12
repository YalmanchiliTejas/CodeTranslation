n,x = map(int,input().split())
 
#レベルnバーガーの構造は、1,2^(n+1)-3,1,2^(n+1)-3,1
 
ans = 0
x2 = x
k=n
while True:
  thk = [1,2**(k+1)-3,1,2**(k+1)-3,1]
  pc = [0,2**k-1,1,2**k-1,0]
  for i in range(5):
    x2-=thk[i]
    if x2<0:
      x2+=thk[i]
      k-=1
      break
    elif x2==0:
      ans+=pc[i]
      print(ans)
      exit()
    else:
      ans+=pc[i]
