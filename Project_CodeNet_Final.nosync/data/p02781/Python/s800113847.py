import numpy as np
import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

N = int(input())
K = int(input())

if int('1' * K) > N:
	print(0)
	sys.exit()

N = str(N)
L = len(N)

def C(a,b):
	out = 1
	for _ in range(b):
		out *= a
		a -= 1
	for bb in range(1,b+1):
		out //= bb
	return out 

def solve(N,n,K):
	if K == 0:
		return 1
	if int('1' * K) > int(N):
		return 0

	ans = 0
	#桁が小さい時
	for i in range(1,n):
		if K - 1 > i - 1:
			continue
		else:
			ans += 9 * C(i-1, K-1) * (9 ** (K-1))
	
	#桁が同じで、先頭が小さい時
	head = int(N[0])
	ans += (head - 1) * C(n-1, K-1) * (9 ** (K-1))

	#桁が同じで先頭も一緒
	sh_N = ''
	for i in range(1,n):
		if N[i] != '0':
			sh_N = N[i:]
			break
	
	if sh_N != '':
		sh_n = len(sh_N)
		ans += solve(sh_N, sh_n, K-1)
	else:
		if K == 1:
			ans += 1

	return ans

answer = solve(N,L,K)

print(answer)
		