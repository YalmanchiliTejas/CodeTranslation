N = int(input())

A = [int(input()) for _ in range(N)]
A.sort()
B = A[::-1]

l1 = []
l2 = []
for i in range((N + int(N % 2 == 0)) // 2):
    l1.append(A[i])
    l1.append(B[i])
    l2.append(B[i])
    l2.append(A[i])

a, b = 0, 0
for i in range(N - int(N % 2 == 1) - 1):
    a += abs(l1[i] - l1[i + 1])
    b += abs(l2[i] - l2[i + 1])

# print(a)
# print(b)
if N % 2 == 0:
    a -= abs(l1[-1] - l1[-2])
    b -= abs(l2[-1] - l2[-2])
    a += max(abs(l1[0] - l1[-1]), abs(l1[-2] - l1[-1]))
    b += max(abs(l2[0] - l2[-1]), abs(l2[-2] - l2[-1]))
else:
    a += max(abs(l1[0] - A[(N - 1) // 2]), abs(l1[-1] - A[(N - 1) // 2]))
    b += max(abs(l2[0] - A[(N - 1) // 2]), abs(l2[-1] - A[(N - 1) // 2]))
res = max(a, b)

# print(l1)
# print(l2)
print(res)
