a="No"
l = list(input())
for i in range(len(l)):
	if i!=0:
		if l[i]!=l[i-1]: a="Yes"
print(a)