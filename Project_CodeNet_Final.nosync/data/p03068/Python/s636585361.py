N=int(input())
S=str(input())
K=int(input())
s=list(S)
t=s[K-1]
a=''
for i in range(N):
  if s[i]!=t:
    s[i]='*'
  a+=s[i]
print(a)
