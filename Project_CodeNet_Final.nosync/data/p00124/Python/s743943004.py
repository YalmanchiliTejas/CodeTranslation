f=0
while 1:
  n=input()
  if n==0: break
  C=[()]*n
  for i in range(n):
    a,b,c,d=raw_input().split(" ")
    C[i]=(i,int(b)*3+int(d),a)
  C=sorted(C,key=lambda x:(-x[1]))
  if f>0: print
  for e in C: print e[2]+","+str(e[1])
  f=1