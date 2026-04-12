n = int(input())
s = input()
k = int(input())

target = s[k-1]

output = []

for i in range(n):
	if s[i]!=target:
		output.append("*")
	else:
		output.append(target)

print("".join(output))