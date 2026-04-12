import sys
n=int(input())
S=[]
for i in range(n):
  s=list(input())
  S+=[s]
ANS=[]
if n==1:
  ANS=S[0]
  ANS.sort()
  ans="".join(ANS) 
  print(ans)
  sys.exit()
for k in range(len(S[0])):
  if S[0][k] in S[1]:
    ANS+=[S[0][k]]
    S[1].remove(S[0][k])
rem=[]
for i in ANS:
  flag=0
  for k in range(2,n):
    if i in S[k]:
      S[k].remove(i)
    elif flag!=1:
      rem+=[i]
      flag=1
for i in rem:
  ANS.remove(i)
ANS.sort()      
ans="".join(ANS)  
print(ans)