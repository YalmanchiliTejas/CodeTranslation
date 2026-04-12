n = input()
s = input()
k = int(input())

target_char = s[k-1]

out = ""
for s_i in s:
	if s_i != target_char:
		out += "*"
	else:
		out += s_i

print(out)