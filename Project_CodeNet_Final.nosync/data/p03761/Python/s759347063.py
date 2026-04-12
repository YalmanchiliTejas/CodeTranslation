import collections
N=int(input())
S=list(input())
ans=collections.Counter(S)

for n in range(N-1):
  S=list(input())
  count_S=collections.Counter(S)
  for k in ans.keys():
    if k in count_S.keys():
      if ans[k]>count_S[k]:
        ans[k]=count_S[k]
    else:
      ans[k]=0
A=[chr(i) for i in range(97,97+26)]
anslist=[]
for l in A:
  if l in ans.keys():
    for n in range(ans[l]):
      anslist.append(l)
print(''.join(anslist))
