N = int(input())
K = int(input())

def c(n,k):
	if k == 0:
		return 1
	elif k == 1:
		return n
	elif k == 2:
		return n*(n-1)//2
	else:
		return n*(n-1)*(n-2)//6
def f(N, K):
	if N == 0 and K > 0:
		return 0

	if K == 0:
		return 1
	digit = len(str(N))
	ret = 0
	if digit > K:
		ret += c(digit-1, K) * (9 ** K)
	a = 10**(digit-1)
	d = N // a
	ret += (d-1) * c(digit-1, K-1) * (9 ** (K-1))
	ret += f(N - d*a, K-1)

	return ret

print(f(N,K))
