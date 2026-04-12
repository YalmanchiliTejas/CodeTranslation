n=int(input())
ans=[]
for i in range(n):
  ans.append(int(input()))
ans.sort()
counter=0
re=[]
for i in range(n):
  re.append(ans[i])
re.reverse()
pointer1=0
pointer2=0
thing=0
a=[]
while counter<n-2:
  if thing==0:
    a.append(ans[pointer1])
    pointer1+=1
    thing=1
  else:
    a.append(re[pointer2])
    pointer2+=1
    thing=0
  counter+=1
final=[]
final.append(re[pointer2])
for i in a:
  final.append(i)
final.append(ans[pointer1])
maxans=0
for i in range(n-1):
  maxans+=abs(final[i]-final[i+1])
pointer1=0
pointer2=0
thing=1
a=[]
counter=0
while counter<n-2:
  if thing==0:
    a.append(ans[pointer1])
    pointer1+=1
    thing=1
  else:
    a.append(re[pointer2])
    pointer2+=1
    thing=0
  counter+=1
final=[]
final.append(re[pointer2])
for i in a:
  final.append(i)
final.append(ans[pointer1])
maxans1=0
for i in range(n-1):
  maxans1+=abs(final[i]-final[i+1])
print(max(maxans1,maxans))