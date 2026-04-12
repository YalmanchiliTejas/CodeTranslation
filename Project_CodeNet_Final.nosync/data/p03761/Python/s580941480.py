N=int(input())
s=[input() for _ in range(N)]
#print(s)

b=[[0 for i in range(26)] for j in range(N)]
for i,ss in enumerate(s):
  for j in list(ss):
      b[i][ord(j)-97]+=1
#print(b)

c=[10**10]*26
for j in range(26):
  for i in range(N):
    c[j]=min(c[j],b[i][j])
#print(c)

ans=[]
for j in range(26):
  ans.append(c[j]*chr(j+97))
print("".join(ans))