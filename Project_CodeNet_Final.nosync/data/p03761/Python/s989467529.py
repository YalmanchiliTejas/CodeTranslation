n = int(input())
s = [input() for i in range(n)]
x = [51]*26
for i in s:
	for j in range(97,123):
		if i.count(chr(j))<x[j-97]:
			x[j-97] = i.count(chr(j))
answer = ""
for i in range(26):
	answer += chr(i+97)*x[i]
print(answer)