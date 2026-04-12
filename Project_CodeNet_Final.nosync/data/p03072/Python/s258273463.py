import sys
input = sys.stdin.readline
'''
allinputs = iter(input().splitlines())
input = lambda : next(allinputs)
#'''

N = int(input())
H = list(map(int, input().split()))

count = 0
max_h = 0

for i in range(N):
	if H[i] >= max_h:
		max_h = H[i]
		count += 1
		
print(count)
