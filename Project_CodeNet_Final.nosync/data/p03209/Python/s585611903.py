def calc(n,x):
  if x==1:
    if n==0:
      ans=1
    else:
      ans=0
  elif 1 < x < (num[n]+1)//2:
    ans= calc(n-1,x-1)
  elif x== (num[n]+1)//2:
    ans= pat[n-1]+1
  elif (num[n]+1)//2 < x <num[n]:
    ans= pat[n-1]+1+ calc(n-1, x- (num[n]+1)//2)
  else:   # x=num[n]
    ans= pat[n]
  return ans


N,X=map(int,input().split())
num= [1]
pat= [1]
for i in range(1,N+1):
  num.append(num[-1]*2+3)
  pat.append(pat[-1]*2+1)

print(calc(N,X))