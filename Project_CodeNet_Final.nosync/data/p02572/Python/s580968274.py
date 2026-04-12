n = int(input())
A = input().split()
A = [int(t) for t in A]

d = 10**9 + 7
s = sum(A)
ans = 0
for i in range(len(A) - 1):
    s = s - A[i]
    ans += A[i] * (s)

print(ans % d)