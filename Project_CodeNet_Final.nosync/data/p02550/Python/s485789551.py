n,x,m = map(int, input().split())

amari = [x]
amariset = {x}
cnt = 0
p = 0

for i in range(n-1):
	a = amari[-1]**2 % m
	if a in amariset:
		p = amari.index(a)
		cnt = i+1-p
		break
	else:
		amari.append(a)
		amariset.add(a)

if cnt == 0:
	print(sum(amari))
	
else:
	n -= len(amari)
	a = n // cnt
	b = n % cnt
	print(sum(amari)+a*sum(amari[p:])+sum(amari[p:(p+b)]))