from collections import Counter
n=int(input())
s=[Counter(list(input())) for _ in range(n)]
c=s[0]
for i in range(1,n):
  c&=s[i]
ans=''
for i in sorted(c.items(),key=lambda x:x[0]):
  ans+=i[0]*i[1]
print(ans)