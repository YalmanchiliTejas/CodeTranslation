from collections import Counter
N=int(input())
S=Counter(list(input()))

for i in range(1,N):
  S_=Counter(list(input()))
  for s in S:
    if S_[s]<S[s]:
      S[s]=S_[s]

ans=[]
for s in S:
  for _ in range(S[s]):
    ans.append(s)
print("".join(sorted(ans)))