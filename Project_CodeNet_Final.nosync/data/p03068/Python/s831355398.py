N = int(input())
S = input()
K = int(input())

a = S[K-1]
b = []
for i in S:
	if(i == a):
		b.append(i)	
	else:
		b.append('*')
t = ''.join(b)
print(t)
