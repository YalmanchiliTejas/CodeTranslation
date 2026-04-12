N, X, M = map(int, input().split())

if X == 0:
    print(0)
    exit()

if N == 1:
    print(X)
    exit()

d = [-1] * (M + 1)
out = [0]
a = X
ans = 0
for i in range(1, N + 1):
    ans += a
    d[a] = i
    out.append(a)
    a = a ** 2 % M
    if a == 0:
        print(ans)
        exit()

    if d[a] != -1:
        loop_num = i + 1 - d[a]
        remain = N - i
        ans += sum(out[d[a]:d[a] + loop_num]) * (remain // loop_num)
        ans += sum(out[d[a]:d[a] + (remain % loop_num)])
        break
print(ans)
