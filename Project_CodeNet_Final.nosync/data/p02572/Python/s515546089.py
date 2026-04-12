def main():
	N = int(input())
	A = [int(a) for a in input().split(" ")]
	p = 1000000007
	S = 0
	Asq = 0
	for i in range(len(A)):
		x = A[i]
		S += x % (2 * p)
		Asq += (x * x) % (2 * p)
	t = ((S * S) % (2 * p) - Asq) % (2 * p)
	print(int(t / 2))

main()