from collections import Counter 
n=int(input())
s=[Counter(list(input())) for i in range(n)]
  
INF=100
a=[INF]*26
for i in s:
  for j in range(26):
    k=j+ord('a')
    a[j]=min(a[j],i[chr(k)])
for i in range(26):
  if a[i]>50:
    a[i]=0
ans=''
for i in range(26):
  ans+=chr(i+ord('a'))*a[i]
print(ans)