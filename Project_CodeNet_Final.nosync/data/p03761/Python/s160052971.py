from collections import Counter,OrderedDict
n=int(input())
s=[ input() for idd in range(n)]
alf=list("abcdefghijklmnopqrstuvwxyz")
ans=OrderedDict()
for idd in alf:
  ans[idd]=1000
for idd in s:
  sl=list(idd)
  sl=OrderedDict(Counter(sl))
  for jdd in alf:
    if not (jdd in sl):
      ans[jdd]=0
    elif ans[jdd]>sl[jdd]:
      ans[jdd]=sl[jdd]
s=""
for idd in ans:
  if ans[idd]!=0:
    s+=str((idd*int(ans[idd])))
print(s)