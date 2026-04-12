N = int(input())
A = list(map(int, input().split()))
m = 10 ** 9 + 7
s = sum(A)
AA = []
for a in A[:-1]:
    s = (s - a) % m
    AA.append(s)
ans = 0
for i in range(N-1):
    ans += (A[i] * AA[i]) % m
ans %= m
print(ans)