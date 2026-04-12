n=int(input())
s=input()
l=int(input())-1
moji=s[l]
M=["*"]*n

for i in range(n):
  if s[i]==moji:
    M[i]=moji
    
ans=""
for i in range(n):
  ans+=M[i]
  
print(ans)