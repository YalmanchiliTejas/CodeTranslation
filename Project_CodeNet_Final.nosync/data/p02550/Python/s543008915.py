n,x,m = map(int,input().split())
ans = 0
l = [x]
s = [0]*m
s[0] = 1

for i in range(n):
	x = (x*x)%m
	if s[x] == 1:
		break
	s[x] = 1
	l.append(x)

if x == 0:
	print(sum(l))
else:
	p = l[0]
	k = 1
	Su = 0
	while p != x and k < len(l):
		Su += p
		p = l[k]
		k += 1
	l = l[k-1:]

	Su2 = 0
	for r in range((n-k)%len(l) + 1):
		Su2 += l[r]
	print(Su + ((n-k)//len(l))*sum(l) + Su2)