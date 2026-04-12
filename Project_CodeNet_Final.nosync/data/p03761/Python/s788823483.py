p="abcdefghijklmnopqrstuvwxyz"
def f(s,a):
  for i in range(len(s)):
    if s[i] in a: a[s[i]]+=1
    else: a[s[i]]=1

n=int(input())
S=input().rstrip()
A={}
f(S,A)
for i in range(1,n):
  S=input().rstrip()
  B={}
  f(S,B)
  for j in range(26):
    if not p[j] in A: continue
    if p[j] in A and p[j] in B:
      A[p[j]]=min(A[p[j]],B[p[j]])
    elif p[j] in A and not p[j] in B:
      del(A[p[j]])
ans=""
for i in range(26):
  if p[i] in A:
    ans=ans+p[i]*A[p[i]]
print(ans)