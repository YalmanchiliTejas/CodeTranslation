N=int(input())
S=input()
K=int(input())
ans=[]
for i in range(N):
  if S[i]!=S[K-1]:
    s="*"
  else:
    s=S[K-1]
  ans.append(s)
print("".join(ans))
