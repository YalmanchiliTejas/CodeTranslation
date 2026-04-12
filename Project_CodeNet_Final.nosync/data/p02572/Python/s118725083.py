N = int(input().strip())
A = list(map(int, input().strip().split()))

def mod(x):
	return x % 1000000007

sa = sum(A[1:])
s = mod(A[0] * sa)

for a in A[1:-1]:
	sa -= a
	s = mod(s + a * sa)

print(s)