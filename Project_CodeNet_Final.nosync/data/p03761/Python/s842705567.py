n=input()
S=[]
min_len=50
for i in range(n):
	x=list(raw_input())
	d={}
	for j in x:
		if not j in d:
			d[j]=1
		else:
			d[j]+=1
	S.append(d)

#print S

l=S[0]

l2={}
min_cnt=50
for i in l.keys():
	for j in S:
		#print i,j,l2
		if i not in j:
			if i in l2:
				l2[i]=-1
		else:
			if i not in l2:
				l2[i]=j[i]
			else:
				if l2[i]!=-1:
					l2[i]=min(l2[i],j[i])		

ans=""
if len(l2.keys())==0:
	pass

else:
	for i in sorted(l2.keys()):
		for j in range(l2[i]):
			ans+=i
print ans
	

