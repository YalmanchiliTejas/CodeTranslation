from bisect import bisect_left

n = int(input())
a = [int(input()) for _ in range(n)]

c = [0] * n
end = n

for ai in a:
    ci = bisect_left(c, ai, end, n)
    c[ci - 1] = ai
    if ci <= end:
        end -= 1
print(n - end)
