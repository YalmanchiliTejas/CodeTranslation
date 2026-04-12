abc = 'abcdefghijklmnopqrstuvwxyz'
n=int(input())
l = [30]*len(abc)
for _ in [0]*n:
  s = input()
  for i in range(len(abc)):
    l[i] = min([l[i],s.count(abc[i])])
ans = ''
for i in range(len(abc)):
  ans+=abc[i]*l[i]
print(ans)