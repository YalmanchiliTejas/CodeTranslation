N = int(input())
a = list(map(int, input().split()))

s = 0
r = [0] * N
r[0] = a[0]

for i in range(1, N):
    r[i] = r[i-1] + a[i]

for i in range(N-1):
    s += a[i] * (r[N-1] - r[i])

print(s % (10 ** 9 + 7))