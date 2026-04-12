N=int(input())
L=[input() for _ in range(N)]
ans=[]

for i in range(26):
  x=chr(ord('a') + i)
  count=50
  for l in L:
    count =min(count,l.count(x))
  else:
    ans.append(x*count)
  
print(''.join(ans))