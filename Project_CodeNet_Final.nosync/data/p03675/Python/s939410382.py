n = int(input())
a = list(map(int, input().split()))

ans = [-1 for i in range(n)]
for i in range(n):
    if i % 2 == 0:
        ans[i // 2] = a[n - i - 1]
    else:
        ans[n - (i // 2 + 1)] = a[n - i - 1]
print(' '.join(map(str, ans)))
