N = int(input())
a = [int(input()) for _ in range(N)]
a.sort()
if N == 2:
    print(a[-1] - a[0])
    exit()

if N % 2 == 0:
    ans = 2 * sum(a[N // 2:]) - 2 * sum(a[:N // 2]) + a[(N // 2) - 1] - a[N // 2]
else:
    ans1 = 2 * sum(a[(N // 2) + 1:]) - 2 * sum(a[:N // 2]) - a[N // 2] + a[(N // 2) - 1]
    ans2 = 2 * sum(a[(N // 2) + 1:]) - 2 * sum(a[:N // 2]) + a[N // 2] - a[(N // 2) + 1]
    ans = max(ans1, ans2)
print(ans)