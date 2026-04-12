#a = int(input())
#b,c = map(int,input().split())
#s = input()
#list_s = list(input())
#list_int = list(map(int,input().split()))

#list = [0 for i in range(n)]
#dp = [[0 for i in range(A)] for j in range(B)]

#list_int 並べて出力 print (' '.join(map(str,ans_li)))
#list_str 並べて出力 print (' '.join(list))

# 2進数 format(10, 'b') # '1010'

# aa=[int(input()) for i in range(n)]

#for i,name in enumerate(list)

''' 二次元配列を一列ずつ
for i in ans:
	print(*i)
'''
''' heapq
queue = []
heapq.heapify(queue) #heapqの作成
heapq.heappush(queue,num) #numのpush(値の追加)
pop = heapq.heappop(queue) #numのpop(最小値の出力)
pop = heapq.heappushpop(queue,num) #push -> pop

'''

from collections import defaultdict
import sys,heapq,bisect,math,itertools,string
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7


N = int(input())
s = input()
s = s + s[0]

def check(SW):
	global N
	global s
	for i in range(1,N+1):
		if SW[i]:
			if s[i] == 'o':
				SW.append(SW[i-1])
			else:
				SW.append(not SW[i-1])
		else:
			if s[i] == 'o':
				SW.append(not SW[i-1])
			else:
				SW.append(SW[i-1])

	if SW[N] == SW[0] and SW[N+1] == SW[1]:
		for i in range(N):
			if SW[i]:
				sys.stdout.write("S")
			else:
				sys.stdout.write("W")
		print()
		sys.exit()

check([True,True])
check([True,False])
check([False,True])
check([False,False])
print(-1)
