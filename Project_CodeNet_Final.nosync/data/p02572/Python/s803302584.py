M = 10**9 + 7
N = int(input())
A = list(map(int, input().split()))

table = [0] * (N)
for i in range(N-1):
    table[i+1] = table[i] + A[N-i-1]
table = table[::-1]

ans = 0
for i in range(N-1):
    ans = (ans + table[i]*A[i]) % M

print(ans)
