x=list(input())
ans='No'
for i in range(len(x)-1):
  if x[i]=='A':
    if x[i+1]=='C':
      ans='Yes'
print(ans)