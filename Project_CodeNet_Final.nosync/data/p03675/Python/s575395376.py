N = int(input())
a = input().split()
b = [""] * N
b1 = [a[i] for i in range(len(a)) if i % 2 == 1][::-1]
b2 = [a[i] for i in range(len(a)) if i % 2 == 0]
b = b1 + b2
if N % 2 == 1:
	b = b[::-1]
line = " ".join(b)
print(line)