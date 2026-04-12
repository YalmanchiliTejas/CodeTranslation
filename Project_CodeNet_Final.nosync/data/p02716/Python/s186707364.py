from sys import stdin
import sys
# sys.setrecursionlimit(10**8)

def nextLine(): return next(stdin)
def nextStrList(): return nextLine().split()
def nextIntList(): return [int(_) for _ in nextStrList()]

# def comp0(n, aList):
# 	num=n//2
# 	score=[[None for _ in range(num)] for i in range(n)]
# 	
# 	for i in range(n):
# 		
# 		if i==0:
# 			score[i][0]=aList[i]
# 		else:
# 			score[i][0]=max(aList[i], score[i-1][0])
# 			
# 		for j in range(1, num):
# 			nextScore=[]
# 			if i>=1:
# 				s=score[i-1][j]
# 				if s is not None:
# 					nextScore.append(s)
# 			if i>=2:
# 				s=score[i-2][j-1]
# 				if s is not None:
# 					s+=aList[i]
# 					nextScore.append(s)
# 			if len(nextScore)>0:
# 				nextScore=max(nextScore)
# 				score[i][j]=nextScore
# 	
# # 		print(i, aList[i], *[str(s) for s in score[i]], sep="\t")
# 	
# 	print(score[-1][-1])
	
	
def comp(n, aList):
	num=n//2
	score=[[None for _ in range(num)] for i in range(3)]
# 	base=[0 for _ in range(num)]
	
	for i in range(n):
		for j in range(max(0, num-(n-i)//2-1), min(i//2+1,num)):
			if j==0:
				if i==0:
					ns=aList[i]
				else:
					ns=max(aList[i], score[(i-1)%3][0])
			else:
				nextScore=[]
				if i>=1:
					s=score[(i-1)%3][j]
					if s is not None:
						nextScore.append(s)
				if i>=2:
					s=score[(i-2)%3][j-1]
					if s is not None:
						s+=aList[i]
						nextScore.append(s)
				if len(nextScore)>0:
					ns=max(nextScore)
			
			score[i%3][j]=ns
	
# 		print(i, *[str(s) for s in score[i%3]], sep="\t")
	
	print(score[(n-1)%3][-1])


def main():
	n=int(nextLine())
	aList=nextIntList()

# 	import numpy as np
# 	n=200000
# # 	aList=list(np.random.randint(-1000000000, 1000000001, n))
# # 	n=22
# 	aList=list(np.random.randint(-9, 10, n))
	
	comp(n, aList)
# 	comp0(n, aList)
	
	
if __name__=="__main__":
	main()
