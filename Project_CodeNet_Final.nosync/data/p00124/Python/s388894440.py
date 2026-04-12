f=0
while 1:
  n=input()
  if n==0: break
  if f>0: print
  C=[()]*n
  for i in range(n):
    s=raw_input()
    p=s.index(" ")
    a,b,c=map(int,s[p+1:].split(" "))
    C[i]=(i,a*3+c,s[:p])
  C=sorted(C,key=lambda x:(-x[1],x[0]))
  for e in C: print e[2]+","+str(e[1])
  f=1