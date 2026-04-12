n = input()
h = list(map(int,input().split()))

h1 = h[0]

n = 1

max = h1

for i in range(1,len(h)):
	if(max <= h[i]):
		n += 1
		max = h[i]

print(n)