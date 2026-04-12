def li():
    return [int(x) for x in input().split()]

N = int(input())
A = li()
d = 10**9 + 7
B = [A[i] % d for i in range(len(A))]

s = 0
s2 = 0
for i in range(len(B)):
    s += B[i]
    s = s
    s2 += B[i] ** 2
    s2 = s2

ans = ((s**2 - s2) // 2) % d

print(ans)