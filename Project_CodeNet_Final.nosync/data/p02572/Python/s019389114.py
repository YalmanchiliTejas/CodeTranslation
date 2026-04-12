n = int(input())
a = list(map(int, input().split()))

all_sum = (sum(a) ** 2)
diff = [(a[i] ** 2) for i in range(n)]

ans = (all_sum - sum(diff)) // 2

print(ans % (10 ** 9 + 7))