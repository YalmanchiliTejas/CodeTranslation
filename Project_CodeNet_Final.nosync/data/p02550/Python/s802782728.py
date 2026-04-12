N,X,M=map(int,input().split())

ans = 0
A = [X]
tmp = X

first=0
firstCnt=0
loop=0
loopLen=0
loopCnt=0
remain=0
remainCnt=0

induces=[ -1 for _ in range(M+1)]

for n in range(1,M+1):
	cur = ( tmp ** 2 ) % M
	if induces[ cur ] != -1:
		index = induces[ cur ]
		first = sum(A[:index])
		firstCnt = len(A[:index])
		loop = sum(A[index:])
		loopLen = len(A[index:])
		loopCnt = (N-firstCnt)//loopLen
		remainCnt = (N-firstCnt)%loopLen
		remain = sum(A[index:index+remainCnt])

		# print(first,firstCnt,loop,loopLen,loopCnt,remainCnt,remain)
		# print(cur, induces[ cur ], A[:induces[ cur ]], A[induces[ cur ]:])
		break
	induces[ cur ] = n
	A.append( cur )
	tmp = cur

ans = first + loop * loopCnt + remain
print( ans )
