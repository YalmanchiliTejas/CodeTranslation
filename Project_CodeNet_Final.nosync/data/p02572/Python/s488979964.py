P = 10**9 + 7

N = int(input())
A = [int(x) for x in input().split()]

S, T = 0, 0
for i in range(N):
    S = (S + A[i]) % P
    T = (T + A[i] * A[i]) % P

U = (S * S - T) % P
ans = (U * (5 * 10**8 + 4)) % P
print(ans)