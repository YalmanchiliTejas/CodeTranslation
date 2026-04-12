n=int(input())
s=input()
p1=["W","W"]
p2=["W","S"]
p3=["S","W"]
p4=["S","S"]
p=[p1,p2,p3,p4]
for i in range(4):
	for j in range(n-2):
		same=0
		if p[i][j+1]=="S" and s[j+1]=="o"\
		or p[i][j+1]=="W" and s[j+1]=="x":
			same=1
		if same and p[i][j]=="S" or not same and p[i][j]=="W":
			p[i].append("S")
		else:
			p[i].append("W")
	f=0
	same=0
	if p[i][-1]=="S" and s[-1]=="o"\
	or p[i][-1]=="W" and s[-1]=="x":
		same=1
	if same and p[i][-2]=="S" or not same and p[i][-2]=="W":
		if p[i][0]=="S":
			f=1
	else:
		if p[i][0]=="W":
			f=1
	if f==0:
		continue
	f=0
	same=0
	if p[i][0]=="S" and s[0]=="o"\
	or p[i][0]=="W" and s[0]=="x":
		same=1
	if same and p[i][-1]=="S" or not same and p[i][-1]=="W":
		if p[i][1]=="S":
			f=1
	else:
		if p[i][1]=="W":
			f=1
	if f:
		ans=""
		for x in p[i]:
			ans+=x
		print(ans)
		exit()
print(-1)