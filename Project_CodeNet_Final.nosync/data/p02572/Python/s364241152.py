mod = 10 ** 9 + 7
n = int(input())
a = list(map(int, input().split()))
ans = 0
sum_arr = sum(a)
for i in a:
    sum_arr -= i
    ans += i * sum_arr
print(ans % mod)
