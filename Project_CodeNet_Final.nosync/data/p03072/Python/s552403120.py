n=int(input())
l=list(map(int, input().split()))
m=0
for i in range(n):
  for j in range(i):
    if l[j]>l[i]:
      break
  else:
    m+=1
print(m)