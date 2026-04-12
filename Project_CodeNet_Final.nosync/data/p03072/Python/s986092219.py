n = int(input())
a = list(map(int,input().split(' ')))
r = 1

for i in range(1,len(a)) :
  if max(a[:i]) <= a[i]:
    r +=1
  else:
    continue
print(r)
  