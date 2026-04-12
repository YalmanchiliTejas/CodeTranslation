n=input()
s=input()
sl=list(s)
k=int(input())

res=[]
c = sl[k-1]
for i in sl:
	if c==i:
		res.append(i)
	else:
		res.append("*")
        
print("".join(res))