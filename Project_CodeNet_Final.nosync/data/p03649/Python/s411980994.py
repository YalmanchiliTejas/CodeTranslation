n = int(input())
a = list(map(int, input().split()))

k = 0
amax = max(a)
while n - 1 < amax:
    for i in range(n):
        if n - 1 < a[i]:
            d = a[i] // n
            k += d
            for j in range(n):
                if j == i:
                    a[j] -= d * n
                else:
                    a[j] += d
    amax = max(a)

print(k)