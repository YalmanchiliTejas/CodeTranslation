H, W = map(int, input().split())
a = [list(input()) for _ in range(H)]

a = list(zip(*[i for i in a if "#" in i]))
a = list(zip(*[j for j in a if "#" in j]))
for n in range(len(a)):
	print("".join(a[n]))
