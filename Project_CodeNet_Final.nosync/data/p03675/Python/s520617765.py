n = int(input())
A = [int(i) for i in input().split()]
B = []
if n%2:
	B = [A[n-1-2*i] for i in range(n//2)]
	B.append(A[0])
	B += [A[2*i+1] for i in range(n//2)]
else:
	B = [A[n-1-2*i] for i in range(n//2)]
	B += [A[2*i] for i in range(n//2)]
print(*B)
