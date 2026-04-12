n = int(input())
a = list(map(int, input().split()))

mod = pow(10, 9) + 7

sum_array = [a[-1]]
for i in range(n - 1):
    sum_array.append(sum_array[i] + a[n - i - 2])

ans = 0
for i in range(n - 1):
    ans += sum_array[n - i - 2] * a[i]

ans %= mod
print(ans)