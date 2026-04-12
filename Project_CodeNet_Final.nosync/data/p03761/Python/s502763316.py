from collections import defaultdict
import sys,heapq,bisect,math,itertools,string
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
AtoZ = [chr(i) for i in range(65,65+26)]
atoz = [chr(i) for i in range(97,97+26)]

N = int(input())
ans = [INF]*26

for i in range(N):
	S = list(input())
	alpha_count = [0]*26
	for s in S:
		ind = atoz.index(s)
		alpha_count[ind] += 1

	for j in range(26):
		ans[j] = min(ans[j],alpha_count[j])

ans_str = ''
for i,num in enumerate(ans):
	for j in range(num):
		ans_str = ans_str + atoz[i]

print(ans_str)