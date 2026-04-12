s=input()
l=[]
for i in range(len(s)):
	l.append(s[i])
s_l=set(l)
print('Yes' if len(s_l)==2 else 'No')