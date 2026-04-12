n, k = map(int, input().split())
print(sum([n // i * (i - k) + max(0, n % i - k + 1)
           for i in range(k + 1, n + 1)]) - (k == 0) * n)
