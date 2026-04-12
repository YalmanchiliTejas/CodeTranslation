from collections import defaultdict
INF = -1000000000000001

n = int(input())
l = list(map(int, input().split()))

a = int(n/2)

dpa = defaultdict(lambda: -INF)
#dpa = [[0 for j in range(a+1)] for i in range(n+1)]

dpa[(0,0)] = 0
dpa[(1,0)] = 0
dpa[(1,1)] = l[0]
j = 1
for i in range(2,n+1):
	if i == j*2:
		dpa[(i,j)] = max(dpa[(i-2,j-1)]+l[i-1],dpa[(i-1,j)])
#		print(i,j,dpa[(i,j)])
	else:
		dpa[(i,j)] = max(dpa[(i-2,j-1)]+l[i-1],dpa[(i-1,j)])
#		print(i,j,dpa[(i,j)])
		if (i != n):
			j += 1
#			print(i,j,dpa[(i,j)])
#			print("   ",i-2,j-1,dpa[(i-2,j-1)],"")
			dpa[(i,j)] = dpa[(i-2,j-1)]+l[i-1]

#print(dpa)
print(dpa[n,a])