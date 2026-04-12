n=int(input())
s=list(input())
k=int(input())
ss = s[k-1]
for i in range(0,n):
  if s[i] != ss:
    s[i]='*'
print("".join(s))