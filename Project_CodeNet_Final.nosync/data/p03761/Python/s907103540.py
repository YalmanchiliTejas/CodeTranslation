n=int(input())
s=[input() for i in range(n)]
l=list("abcdefghijklmnopqrstuvwxyz")
c_tmp=[]
for j in l:
  for i in s:
    c_tmp.append(i.count(j))
  print(j*min(c_tmp),end="")
  c_tmp.clear()