from string import ascii_lowercase
n=int(input())
s=[]
for i in range(n):
  s.append(input())
ans={}
for i in ascii_lowercase:
  ans[i]=s[0].count(i)
for i in range(1,n):
  for j in ascii_lowercase:
    ans[j]=min(ans[j],s[i].count(j))
a=""
for i in ascii_lowercase:
  a+=i*ans[i]
print(a)