n=int(input());a=list(map(int,input().split()))[::-1]
result=0
for i in range(n):
  judge=True
  for j in range(i+1,n):
    if a[i]<a[j]:
      judge=False
      break
  if judge: result+=1
print(result)