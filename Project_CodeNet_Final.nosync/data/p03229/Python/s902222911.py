n = int(input())
arr = [int(input()) for x in range(n)]

arr.sort()

med = n // 2

# 偶奇で場合分け
if n % 2 == 0:
    ans = 2 * sum(arr[med + 1:]) - 2 * sum(arr[:med - 1]) + arr[med] - arr[med - 1]
# 初項と末項の組み合わせ方で場合分け
else:
    ans1 = 2 * sum(arr[med + 1:]) - 2 * sum(arr[:med - 1]) - arr[med - 1] - arr[med]
    ans2 = 2 * sum(arr[med + 2:]) - 2 * sum(arr[:med]) + arr[med + 1] + arr[med]
    ans = max(ans1, ans2)

print(ans)