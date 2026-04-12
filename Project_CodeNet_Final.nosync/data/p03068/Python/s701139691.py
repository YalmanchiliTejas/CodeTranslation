N=int(input())
S=input()
K=int(input())
s=S[K-1]
l=list(S)
for i in range(N):
  if l[i]!=s:
    l[i]="*"
print("".join(l))