N = int(input())

a = [int(input()) for _ in range(N)]

ans = [a[0]]

for i in range(1, N):

    if  ans[len(ans) - 1] >= a[i]:
        ans.append(a[i])
    elif ans[0] < a[i]:
        ans[0] = a[i]
    elif ans[len(ans) - 2] >= a[i]:
        ans[len(ans) - 1] = a[i]
    else:
        l = 0
        h = len(ans) - 1
        m = (l + h) // 2
        while True:
            if ans[m] >= a[i]:
                l = m
                m = (l + h) // 2
                continue

            if ans[m - 1] < a[i]:
                h = m
                m = (l + h) // 2
                continue
            break
        ans[m] = a[i]

print(len(ans))
