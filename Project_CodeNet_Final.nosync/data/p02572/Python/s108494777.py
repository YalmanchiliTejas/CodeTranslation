n = int(input())
a = list(map(int, input().split()))
mod = 10 ** 9 + 7

tmp = 0
li = []
for i in range(n - 1, 0, -1):
    tmp += a[i]
    li.append(tmp * a[i - 1])

print(sum(li) % mod)
