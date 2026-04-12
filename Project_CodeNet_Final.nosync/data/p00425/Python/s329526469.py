class diceClass:
	def __init__(self, valuelist):
		# [t, s, e, w, n, b]
		self.valuelist = valuelist
		self.t = valuelist[0]
		self.s = valuelist[1]
		self.e = valuelist[2]
		self.w = valuelist[3]
		self.n = valuelist[4]
		self.b = valuelist[5]

	def print(self):
		print('t={0}, s={1}, e={2}, w={3}, n={4}, b={5}'.format(self.t, self.s, self.e, self.w, self.n, self.b))

	def throw(self, direction):
		# N,S,W,E
		if direction == 'North':
			self.t, self.s, self.b, self.n = self.s, self.b, self.n, self.t
		elif direction == 'South':
			self.t, self.s, self.b, self.n = self.n, self.t, self.s, self.b
		elif direction == 'West':
			self.t, self.e, self.b, self.w = self.e, self.b, self.w, self.t
		elif direction == 'East':
			self.t, self.e, self.b, self.w = self.w, self.t, self.e, self.b
		elif direction == 'Right':
			self.s, self.e, self.w, self.n = self.e, self.n, self.s, self.w
		elif direction == 'Left':
			self.s, self.e, self.w, self.n = self.w, self.s, self.n, self.e


while True:
	n = int(input())
	if n == 0:
		break
	A = [1, 2, 3, 4, 5, 6]
	dice = diceClass(A)
	tsum = dice.t
	for i in range(n):
		s = input().strip()
		dice.throw(s)
		tsum = tsum + dice.t
	print(tsum)

