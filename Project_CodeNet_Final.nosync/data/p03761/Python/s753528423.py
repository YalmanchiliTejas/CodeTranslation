from collections import Counter
n=int(input())
s=set()
d={}

for i in range(n):
  st=input()
  b={i for i in st}
  d[i]=Counter(st)
  if not i:
    s=s|b
  else:
    s=s&b

buf=""
l=sorted(s)
for j in l:
  buf+=j*min([i[j] for i in d.values()])
print(buf)