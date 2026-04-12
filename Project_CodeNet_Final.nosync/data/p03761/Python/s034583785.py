l=[51]*26
N = int(input())

for s in [input() for _ in range(N)]:
  for i in range(26): 
    c=s.count(chr(97+i))
    l[i]=min(l[i],c)
ans=''
for i in range(26):
  if l[i]<51: ans += chr(97+i)*l[i]
print(ans)