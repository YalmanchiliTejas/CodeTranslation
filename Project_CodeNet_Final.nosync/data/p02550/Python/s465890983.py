n, x, m = map(int, input().split())
a = [-1 for _ in range(10 ** 5 + 2)]
memo = [-1 for _ in range(m)]
a[1] = x
for i in range(2, 10 ** 5 + 2):
    a[i] = a[i-1] ** 2 % m
    if memo[a[i]] == -1:
        memo[a[i]] = i
    else:
        one_loop = i - memo[a[i]]
        start_loop = memo[a[i]]
        break


if start_loop >= n:
    print(sum(a[1:n+1]))
else:
    ans = sum(a[1:start_loop])
    loop, res = divmod(n - start_loop + 1, one_loop)
    ans += sum(a[start_loop: start_loop + one_loop]) * loop
    ans += sum(a[start_loop: start_loop + res])   
    print(ans) 
    