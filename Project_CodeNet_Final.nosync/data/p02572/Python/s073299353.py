import math

class BitIndexedTree:
	'''NOTES: 1-origin-indexed
	'''
	def __init__(self, itemCount):
		self.itemCount = itemCount
		self.items = [0 for i in range(itemCount+1)]

	def add(self, i,value):
		while i <= self.itemCount:
			self.items[i] += value
			i += (i & (-i))

	def sumFromStart(self, end):
		summary = 0
		i = end
		while i > 0:
			summary += self.items[i]
			i -= (i & (-i))
		return summary

	def sum(self, start,end):
		summary = self.sumFromStart(end) - self.sumFromStart(start-1)
		return summary

if __name__ == "__main__":
	MOD = 10 ** 9 + 7
	N=int(input())
	A=list(map(int,input().split()))

	BIT=BitIndexedTree(N)

	for n in range(N):
		BIT.add(n+1, A[n])

	ans = 0
	for n in range(N-1):
		# print(A[n],BIT.sum(n+2,N),A[n] * BIT.sum(n+2,N))
		# print(MOD)
		ans += ((A[n] * BIT.sum(n+2,N)) % MOD)


	print(ans % MOD)






