H, W = map(int, input().split())
a = list(zip(*[j for j in list(zip(*[i for i in [list(input()) for _ in range(H)] if "#" in i])) if "#" in j]))
for n in range(len(a)):
	print("".join(a[n]))
