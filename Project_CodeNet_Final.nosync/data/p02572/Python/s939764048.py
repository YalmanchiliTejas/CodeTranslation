N = int(input())
A = list(map(int, input().split()))

ans = 0
s = sum(A)
for i, x in enumerate(A):
	s -= x
	ans += s * x
	ans %= 10 ** 9 + 7

print (ans)
