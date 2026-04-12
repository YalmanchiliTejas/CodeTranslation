n = int(input())
a = list(map(int, input().split()))

i = 0
ans = 0
while max(a) >= n:
    if a[i] >= n:
        cnt = a[i] // n
        ans += cnt
        a[i] -= n * cnt
        for j in range(n):
            if j == i:
                continue
            a[j] += cnt

    i = (i + 1) % n

print(ans)
