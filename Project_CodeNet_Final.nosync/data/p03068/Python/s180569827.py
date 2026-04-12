n ,s ,k =  int(input()),input(), int(input())
b = s[k-1]
for i in range(len(s)):
	if s[i] != b:
		print('*',end= '')
	else:print(b, end = '')
print()