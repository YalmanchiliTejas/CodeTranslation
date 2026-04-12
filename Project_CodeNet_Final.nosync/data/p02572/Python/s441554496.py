m = 1000000007

N, *A = map(int, open(0).read().split())

result = 0
c = 0
for a in A:
    result += c * a
    result %= m
    c += a
    c %= m
print(result)
