num = int(input())
L = []
al = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]
for xx in range(num):
	lis = []
	S = input()
	for yy in range(26):
		LL = S.count(al[yy])
		lis.append(LL)
	L.append(lis)
st = ""
for i in range(26):
	xxx = []
	for j in range(num):
		xxx.append(L[j][i])
	nn = min(xxx)
	st += al[i] * nn
print(st)
