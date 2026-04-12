n=int(input())
s=input()
k=int(input())

t=str()
val=s[k-1]
for i in range(n):
  if s[i]==val:
    t+=val
  else:
    t+='*'
    
print(t)
   