N,X,M=map(int,input().split())
lst=[]
n,s=X,0
for i in range(N):
  if n in lst:break
  lst.append(n)
  n=(n*n)%M
if len(lst)<N:
  k=lst.index(n)
  s1=sum(lst[:k])
  s2=sum(lst[k:])*((N-k)//(len(lst)-k))
  s3=sum(lst[k:k+(N-k)%(len(lst)-k)])
  s=s1+s2+s3
else:s=sum(lst)
print(s)