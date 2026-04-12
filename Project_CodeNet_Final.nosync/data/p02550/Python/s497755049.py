#from collections import deque
#from heapq import heapify, heappop, heappush
#from bisect import insort
#from math import gcd
#mod = 10**9 + 7
#N = int(input())
N, X, M = map(int, input().split())
count = [(-1, 0) for _ in range(M)]
now = X
cnt = 0
ans = 0
roop = 0
roopsum = 0
while count[now][0] < 0 and cnt < N:
	cnt += 1
	ans += now
	count[now] = (cnt, ans)
	now = now*now%M
	#print(ans)
	if count[now][0] > 0 and cnt < N-1:
		start = count[now][0]
		end = cnt+1
		roop = end - start
		roopsum = ans+now - count[now][1]
#print(count)
#print(start, end)
#print(roop)

#print(roopsum)
if roop == 0:
	print(ans)
	exit()
ans += ((N-end+1)//roop)*roopsum
res = (N-end+1)%roop
for k in range(res):
	ans += now
	now = now*now%M
print(ans)

#A = list(map(int, input().split()))
#flag = True
#for k in range(N):
#ans = 0
#print(ans)
#print('Yes')
#print('No')