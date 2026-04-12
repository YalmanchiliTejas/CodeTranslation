n = int(input())
a = list(map(int, input().split(" ")))

ans = 0
den = int(1e9 + 7)
sum_a = [0 for i in range(len(a))]
sum_a[-1] = a[-1]
for i in range(len(a) - 1, 1, -1):
    sum_a[i - 1] = sum_a[i] + a[i - 1]
for i in range(len(a) - 1):
    ans = (ans + a[i] * sum_a[i + 1]) % den

print(ans)