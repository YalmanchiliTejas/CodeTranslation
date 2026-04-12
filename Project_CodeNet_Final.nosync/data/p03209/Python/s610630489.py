N,X = map(int,input().split(' '))

'''
N = 2
X = 7
'''

def ban(n):
	if n == 0:
		return 'P'
	return 'B'+ban(n-1)+'P'+ban(n-1)+'B'

def ans(n,x):
	if x <= 0:
		return 0
	if n == 0:
		return 1
	s = 2**(n+2) - 3
	a = (s-3)//2
	if x < 2+a:
		return ans(n-1,x-1)
	if x == 2+a:
		return ans(n-1,x-1)+1
	p = 2**(n)-1
	return p + 1+ans(n-1,x-2-a)

print(ans(N,X))

#ans = ban(N)[0:X]
#print(ans.count('P'))

