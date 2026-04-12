n=int(input())
test="abcdefghijklmnopqrstuvwxyz"
c=[[0for i in range(n)]for j in range(26)]
for j in range(n):
  s=input()
  for i in range(26):
    c[i][j]+=list(s).count(test[i])
minl=[]
for i in range(26):
  minl.append(min(c[i]))
outp=""
#print(minl)
for i in range(26):
  outp+=test[i]*minl[i]
print(outp)