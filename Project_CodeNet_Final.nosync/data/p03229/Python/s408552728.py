n = int(input())
a = [int(input()) for _ in range(n)]
a.sort()
if n % 2 == 0:
    half_n = n // 2
    pre = a[:half_n]
    post = a[half_n:]
    print((sum(post) * 2 - post[0]) - (sum(pre) * 2 - pre[-1]))
else:
    half_n = n // 2
    pre1 = a[:half_n]
    post1 = a[half_n:]
    pre2 = a[:half_n+1]
    post2 = a[half_n+1:]
    diff1 = (sum(post1) * 2 - post1[0] - post1[1]) - sum(pre1) * 2
    diff2 = sum(post2) * 2 - (sum(pre2) * 2 - pre2[-1] - pre2[-2])
    print(max(diff1, diff2))