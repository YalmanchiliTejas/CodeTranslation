N, X, mod = map(int, input().split())

val = [-1] * (mod + 100)
val[X] = 1

a = X
idx = 2
memo = [X]

while True:
    a = a * a % mod
    if val[a] != -1:
        last = a
        break
    memo.append(a)
    val[a] = idx
    idx += 1

# print(memo)
# print(last)

if N <= len(memo):
    print(sum(memo[:N]))
else:
    ans = sum(memo)
    N -= len(memo)
    i = memo.index(last)
    L = len(memo) - i

    sm = sum(memo[i:])
    d, m = divmod(N, L)
    ans += sm * d
    for x in range(i, i + m):
        ans += memo[x]
    print(ans)