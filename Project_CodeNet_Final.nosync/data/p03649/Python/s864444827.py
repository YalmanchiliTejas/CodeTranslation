N = int(input())
a = list(map(int, input().split()))
count = 0

while max(a) >= N:
    plus = 0

    for i in range(N):
        plus += a[i] // N
        a[i] = a[i] % N - a[i] // N

    count += plus
    for j in range(N):
        a[j] += plus

print(count)
