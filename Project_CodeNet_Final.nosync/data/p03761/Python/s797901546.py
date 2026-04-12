n=int(input())
chrs=[[0]*26 for i in range(n)]
docs=[input() for i in range(n)]
ansl=[0]*26
for i in range(n):
  for j in docs[i]:
    chrs[i][ord(j)-97]+=1
for i in range(26):
  least=100
  for j in range(n):
    if chrs[j][i]<least:
      least=chrs[j][i]
  ansl[i]=least
ans=""
for i in range(26):
  ans+=chr(97+i)*ansl[i]
print(ans)