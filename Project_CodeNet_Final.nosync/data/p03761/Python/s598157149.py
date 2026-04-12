n=int(input())
s=[list(input()) for _ in range(n)]
a=list('')
for i in s:
  a=set(list(a)+list(i))
a=sorted(list(a))
count=[100]*len(a)
for i in range(len(a)):
  for j in s:
    count[i]=min(count[i],j.count(a[i]))
  a[i]=a[i]*count[i]
print(''.join(a))