n = int(input())
a = list(map(int, input().split()))
sums = [sum(a)]
cnt = 0
N = 10 ** 9 + 7

for i in range(n-1):
    sums.append((sums[-1] - a[i]) % N)

for i in range(n-1):
    cnt += a[i] * sums[i+1]
    cnt %= N

print(cnt)