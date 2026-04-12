import sys
import itertools
if sys.platform =='win32':
	sys.stdin=open('input.txt')
input = sys.stdin.readline
def MAP(): return [int(x) for x in input().split()]


N, M = MAP()
G = [[] for _ in range(N)]
for i in range(M):
	a,b = MAP()
	G[a-1].append(b-1)
	G[b-1].append(a-1)

permutations = (list(itertools.permutations(range(len(G)))))

paths = [p for p in permutations if p[0]==0]

count = 0
for path in paths:
	#print(path)
	for idx,v in enumerate(path):
		if idx == len(path)-1:
			count+=1
			break
		if path[idx+1] in G[v]: continue
		else: break

print(count)