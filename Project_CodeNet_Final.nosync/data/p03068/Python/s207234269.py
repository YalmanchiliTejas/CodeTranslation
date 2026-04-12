N=input()
S=str(input())
K=int(input())
Ans=""
for i in range(0,len(S),1):
  if S[i]==S[K-1]:
    Ans+=str(S[i])
  elif S[i]!=S[K-1]:
    Ans+="*"

print(Ans)
