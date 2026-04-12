n=int(input())
s=input()

d={}
t={}
for i in range(ord("a"),ord("z")+1):
  d[chr(i)]=0
  t[chr(i)]=0
  
for i in s:
  d[i]+=1
for i in range(n-1):
  s=input()
  for j in s: t[j]+=1
  for j in t: d[j]=min(d[j],t[j])
  for j in s: t[j]=0
ans=[]
for i in d:
  for j in range(d[i]):
    ans.append(i)
ans.sort()
x="".join(ans)
print(x)
