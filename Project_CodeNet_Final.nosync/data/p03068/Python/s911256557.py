n=int(input())
s=input()
k=int(input())
c=s[k-1]
sl=list(s)
for i in range(n):
	if sl[i] != c:
		sl[i] = '*'

print("".join(sl))