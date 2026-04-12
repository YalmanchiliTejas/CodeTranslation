a,b=map(int,input().split())
#print(a)
c=[list(input()) for i in range(a)]
#print(c[0])
d=['.'for i in range(b)]
#print(d)
e=[]
for i in range(a):
	if c[i]!=d:
		e.append(c[i])
#print(e)
#for k in range(len(e)):
f=[]
for i in zip(*e):
	f.append(list(i))
#print(f)

g=['.'for i in range(len(e))]
#print(g)
h=[]
for i in range(len(f)):
	if f[i]!=g:
		h.append(f[i])
#print(h)
j=[]
for i in zip(*h):
	j.append(list(i))
for i in range(len(j)):
	print(''.join(j[i]))
