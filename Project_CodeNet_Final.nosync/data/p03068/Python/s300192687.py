N=int(input())
S=input()
K=int(input())
C=S[K-1]
S_=''
for c in S:
  if c == C:
    S_+=c
  else:
    S_+="*"
print(S_)