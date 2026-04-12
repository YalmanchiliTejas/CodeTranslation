n, k = map(int, input().split())

res = 0
if k == 0:
    print(n*n)
    exit()

for i in range(k+1, n+1):
    cnt = (i-1)-k+1
    add = n // i * cnt
    if n % i >= k:
        add += (n % i) - k + 1
    res += add

print(res)
