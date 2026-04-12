a=int(input())
b=input()
c=int(input())
word=b[c-1]
d=[]
for i in range(a):
    if b[i]!=word:
        d.append("*")
    else:
        d.append(b[i])
for s in d:
  print(s, end ="")