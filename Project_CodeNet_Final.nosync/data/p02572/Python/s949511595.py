n = int(input())
aaa = list(map(int, input().split()))
ans = 0
mod = 10 ** 9 + 7
sum_a = [0] * len(aaa)
sum_a[0] = aaa[0]
for i in range(n - 1):
    sum_a[i + 1] = sum_a[i] + aaa[i + 1]

for i in range(n):
    ans += aaa[i] * (sum_a[n -1] - sum_a[i])

print(ans%mod)
