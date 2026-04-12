l=[51]*26
for s in [input() for _ in range(int(input()))]:
  for i in range(26): c=s.count(chr(97+i)); l[i]=min(l[i],c)
a=''
for i in range(26):
  if l[i]<51: a+=chr(97+i)*l[i]
print(a)