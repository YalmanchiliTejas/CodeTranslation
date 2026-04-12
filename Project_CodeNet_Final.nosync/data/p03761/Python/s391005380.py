N=int(input())
S=[]
T=set()
for i in range(ord('a'),ord('z')+1):
	T.add(chr(i))

D={}
for i in range(N):
	d={}
	t=set()
	s=list(input())
	s.sort()
	for j in s:
		if j not in d:
			d[j]=1
			t.add(j)
		else:d[j]+=1
	
	for j in d:
		if j not in D:
			D[j]=d[j]
		else:
			D[j]=min(D[j], d[j])
	
	T&=t

T=sorted(list(T))

if len(T)!=0:
	for i in T:
		print(i*D[i],end='')
	print()