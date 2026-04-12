n = int(input())
s = input()
k = int(input())
c = s[k-1]
s2 = ""
for m in range(n):
	if s[m] == c:
		s2 += c
	else:
		s2 += '*'
        
print(str(s2))