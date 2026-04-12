N = int(input())
A = [int(i) for i in input().split()]

ans = 0
while any(a > N - 1 for a in A):
    S = sum(a // N for a in A)
    A = [a + (S - a // N) - (a // N) * N for a in A]
    ans += S

print(ans)