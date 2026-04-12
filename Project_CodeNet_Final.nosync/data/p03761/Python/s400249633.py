n=int(input())
#print(n)

#l=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
l='abcdefghijklmnopqrstuvwxyz'
#print(len(l))

ansl=[0 for i in range(26)]
#print(ansl)

s=input()  
for j in range(26):
      ansl[j]=s.count(l[j])

if n > 1:
  for i in range(1,n):
    s=input()  
    for j in range(26):
      ansl[j]=min(s.count(l[j]),ansl[j])

ans=''
for i in range(26):
  for j in range(ansl[i]):
    ans+=l[i]
    
print(ans)