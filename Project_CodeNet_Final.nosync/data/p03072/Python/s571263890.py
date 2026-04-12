input()
lst=[int(i) for i in input().split()]
ans=0
_max=lst[0]
for i in lst:
  if i>=_max:
    ans+=1
    _max=i
print(ans)  