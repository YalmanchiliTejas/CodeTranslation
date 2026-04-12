a,b= map(int,input().split())

l = 1

c = [1]
d = [1]

for i in range(50):
	c.append(2*c[-1]+3)
	d.append(2*d[-1]+1)
k = 0
while True:
	if a == 0:
		k += 1
		break
	elif b==1:
		break
	elif c[a] // 2 == b:
		k += d[a-1]
		break
	elif c[a] // 2 > b:
		a -= 1
		b -= 1
	elif c[a] // 2 + 1 == b:
		k += 1 + d[a-1]
		break
	elif c[a] // 2 + 1 < b and c[a] != b:
		a -= 1
		k += d[a]+1
		b -= c[a]+2
	else:
		k += d[a]
		break


print(k)