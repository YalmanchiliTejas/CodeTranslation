f=0
while 1:
  n=input()
  if n==0: break
  C=[()]*n
  for i in range(n):
    s=raw_input().split(" ")
    C[i]=(i,int(s[1])*3+int(s[3]),s[0])
  C=sorted(C,key=lambda x:(-x[1]))
  if f>0: print
  for e in C: print e[2]+","+str(e[1])
  f=1