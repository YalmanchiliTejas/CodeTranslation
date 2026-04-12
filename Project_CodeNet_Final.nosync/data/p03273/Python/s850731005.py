H, W = map(int, input().split())
a = [list(input()) for _ in range(H)]
a = [i for i in a if "#" in "".join(i)]
# print("step1", a)
a = list(zip(*a))
# print("step2", a)
a = [j for j in a if "#" in "".join(j)]
# print("step3", a)
a = list(zip(*a))
# print("step4", a)
for n in range(len(a)):
	print("".join(a[n]))
