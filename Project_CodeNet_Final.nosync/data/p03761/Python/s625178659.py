import sys
from collections import Counter

if sys.platform in ['ios','win32','darwin']:
	sys.stdin=open('Untitled.txt')
input = sys.stdin.readline
def INT(): return int(input())
def MAP(): return [int(s) for s in input().split()]

N = INT()
A = [input().rstrip() for _ in range(N)]

C = [Counter(a) for a in A]
#print(A)
#print(C)

tmp = {}

for k, v in C[0].items():
	tmp[k] = v
	for i in range(N):
		tmp[k] = min(tmp[k], C[i][k])

tmp = sorted(tmp.items(), key=lambda x:x[0])
#print(tmp)

ans = ''
for k, v in tmp:
	ans += k * v

print(ans)