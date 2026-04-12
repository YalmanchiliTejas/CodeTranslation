n=int(input())
dp=[0]*26
for i in range(n):
  S=input()
  for j in range(26):
    p=0
    for k in range(len(S)):
      if S[k]==chr(j+97):
        p+=1
    if i==0:
      dp[j]=p
      continue
    dp[j]=min(dp[j],p)
s=''
for i in range(26):
  for j in range(dp[i]):
    s+=chr(i+97)
print(s)