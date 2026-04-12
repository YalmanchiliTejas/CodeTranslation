N = int(input())
S = input()
K = int(input())

sk = S[K-1]

result = []
for s in S:
	if s != sk:
		result.append("*")
	else:
		result.append(s)
 
print("".join(result))