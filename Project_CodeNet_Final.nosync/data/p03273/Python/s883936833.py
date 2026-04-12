H,W=map(int,input().split())
a=[]
for i in range(H):
    aa=list(input())
    if "#" in aa:
	    a.append(aa)
#print(a)

l=[]
for j in range(W):
  b = [x[j] for x in a]
  if '#' in b:
    #print(b)
    l.append(b)
    

for k2 in range(len(l[0])):
  for k in range(len(l)):
  	print(l[k][k2],end='')
  print("")

    