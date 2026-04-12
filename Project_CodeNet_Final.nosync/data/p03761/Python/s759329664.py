n = int(input())
s = [input() for i in range(n)]
alphabet = [chr(i) for i in range(97, 97+26)]
num = list()
ans = ""

for j in range(0, 26):
	for i in range(0, n):
		num.append(50)
		if list(s[i]).count(alphabet[j]) < num[j]:
			num[j] = s[i].count(alphabet[j])
	for k in range(num[j]):
		ans += alphabet[j]
print(ans)