N=input()
s=list(raw_input())

def judge(a,b):
	t=[]
	t.append(a)
	t.append(b)

	for ind, i in enumerate(s):
		if ind==0:
			continue

		if i=="o" and t[ind]=="S":
			t.append(t[ind-1])
		elif i=="o" and t[ind]=="W":
			if t[ind-1]=="S":
				t.append("W")
			elif t[ind-1]=="W":
				t.append("S")
		elif i=="x" and t[ind]=="S":
			if t[ind-1]=="S":
				t.append("W")
			elif t[ind-1]=="W":
				t.append("S")
		elif i=="x" and t[ind]=="W":
			t.append(t[ind-1])

	if t[0]==t[-1]:
		if s[0]=="o" and t[0]=="S":
			if t[1]==t[-2]:
				print "".join(t[:-1])
				quit()
		elif s[0]=="o" and t[0]=="W":
			if t[1]!=t[-2]:
				print "".join(t[:-1])
				quit()
		elif s[0]=="x" and t[0]=="S":
			if t[1]!=t[-2]:
				print "".join(t[:-1])
				quit()
		elif s[0]=="w" and t[0]=="W":
			if t[1]==t[-2]:
				print "".join(t[:-1])
				quit()			
	else:
		return False

judge("S","S")
judge("S","W")
judge("W","S")
judge("W","W")
print -1


