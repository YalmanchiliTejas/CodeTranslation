abc="abcdefghijklmnopqrstuvwxyz"
n=int(input())
hoge=[]
for i in range(n):
  hoge.append(input())

for i in range(len(abc)):
  huga=[]
  for j in range(n):
    huga.append(hoge[j].count(abc[i]))
  for j in range(min(huga)):
    print(abc[i],end="")