input()
s = input()
k = int(input())
k-=1
p = s[k]
r = ''
for i in s:
	if i!=p:
		r+='*'
	else:
		r+=p
print(r)