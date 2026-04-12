n = int(input())
A = [int(input()) for i in range(n)]

B = A[:]
A.sort()
B.sort(reverse=True)
A = [A[(n-1)//2]] + [A[0]] + A[1:n//2]

ans = 0
prev = A[0]
for i in range(n):
    if i % 2 == 0:
        ans += abs(prev-A[i//2])
        prev = A[i//2]
    else:
        ans += abs(prev-B[i//2])
        prev = B[i//2]

A = B[:]
A.sort()
B = [B[(n-1)//2]] + [B[0]] + B[1:n//2]

ans2 = 0
prev = B[0]

for i in range(n):
    if i % 2 == 1:
        ans2 += abs(prev-A[i//2])
        prev = A[i//2]
    else:
        ans2 += abs(prev-B[i//2])
        prev = B[i//2]

print(max(ans, ans2))