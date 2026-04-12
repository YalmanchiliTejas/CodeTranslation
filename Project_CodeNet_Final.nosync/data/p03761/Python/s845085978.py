n=int(input())
s=input()
a=[0]*26
for j in range(len(s)):
	a[ord(s[j])-ord("a")]+=1
for i in range(n-1):
	s=input()
	b=[0]*26
	for j in range(len(s)):
		b[ord(s[j])-ord("a")]+=1
	for j in range(26):
		a[j]=min(a[j],b[j])
x=""
for i in range(26):
	x+=chr(97+i)*a[i]
print(x)
