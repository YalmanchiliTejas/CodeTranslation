import sys

n = int(sys.stdin.readline().strip())
a = {}
for line in sys.stdin.readlines():
	b = {}
	for x in line.strip():
		if x not in b:
			b[x]=0
		b[x]=b[x]+1
	
	if a=={}:
		a = b
	else:
		for key in a.keys():
			if key not in b:
				a[key] = 0
			else:
				a[key]=min(a[key],b[key])
result = ""
for key in sorted(a.keys()):
	result = result + key*a[key]
print(result)
