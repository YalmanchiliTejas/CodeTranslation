n = int(input())
s = input()
k = int(input())
for i in s:
	print('*' if i != s[k - 1] else i,end='')
print()