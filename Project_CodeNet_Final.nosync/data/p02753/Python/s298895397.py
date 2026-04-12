from collections import Counter
a=list(input())
d=Counter(a).most_common()
if len(d)==2:
	print("Yes")
else:
	print("No")



