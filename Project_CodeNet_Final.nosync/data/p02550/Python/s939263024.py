n, x, m = map(int, input().split())

lst = set()
num = []
for i in range(1, n + 1):
    lst.add(x), num.append(x)
    x = x ** 2 % m
    if x in lst:
        cnt, idx = i, num.index(x)
        div, mod = divmod(n - cnt, len(num) - idx)
        ans = sum(num[:idx + mod])
        ans += sum(num[idx:]) * (div + 1)
        break
else:
    ans = sum(num)
print(ans)
