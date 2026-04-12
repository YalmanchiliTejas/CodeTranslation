N=int(input())
H=input()
ListA=[]
ListA=H.split()
for i in range(0,len(ListA),1):
  a=ListA.pop(i)
  b=int(a)
  ListA.insert(i,b)

c=0
for i in range(0,len(ListA),1):
  ListB=ListA[0:i+1]
  if ListA[i]>=max(ListB):
    c+=1

print(c)
