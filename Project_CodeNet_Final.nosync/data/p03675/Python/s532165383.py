n = int(input())
a = list(map(int,input().split()))

if n == 1:
	print(a[0])
elif n % 2 == 0:
	print(" ".join(map(str, a[1::2][::-1] + a[0::2])))
else:
	print(" ".join(map(str, a[0::2][::-1] + a[1::2])))