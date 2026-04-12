import sys
if sys.platform == 'ios':
	sys.stdin = open('input.txt')
	
n,m = map(int,input().split())

#各頂点のパスはタプルで書く
path = {i+1:[] for i in range(n)}

#各頂点が、どの頂点に繋がっているかのリストを入力しながら作る。
for i in range(m):
	a,b = map(int,input().split())
	path[a].append(b)
	path[b].append(a)

#1は根なので不要。2,3,...,nのリストを作る。
chk = [i for i in range(2,n+1)]
ans = 0

import itertools

#fは辿った頂点の数
#intertools.permurationsで頂点の総並び替えを出す
for way in itertools.permutations(chk):
	#print(way)
	now = 1
	f = 0
	
	for j in way:
		if j in path[now]:
			f = f + 1
			now = j
		else:
			break
		
	if f + 1 == n: # +1するのは根の分
		ans = ans + 1

print(ans)
		
		

