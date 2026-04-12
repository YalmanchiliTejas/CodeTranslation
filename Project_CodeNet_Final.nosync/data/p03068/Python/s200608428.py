a = int(input())
b = list(input())
c = int(input()) - 1
ch = b[c]
for i in range(len(b)):
	if(b[i] != ch):
		b[i] = "*"
print(''.join(b))