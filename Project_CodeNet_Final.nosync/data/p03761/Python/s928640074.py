capital=[[0,100] for i in range(26)]
small=list('abcdefghijklmnopqrstuvwxyz')
n=int(input())
for i in range(n):
  k=input()
  stack=[0]*26
  for j in range(len(k)):
    stack[small.index(k[j])]+=1
  for j in range(26):
    if stack[j]!=0:
      capital[j][0]+=1
      capital[j][1]=min(capital[j][1],stack[j])
ans=[]
for i in range(26):
  if capital[i][0]==n:
    for j in range(capital[i][1]):
      ans.append(small[i])
ans.sort()
print(''.join(ans))