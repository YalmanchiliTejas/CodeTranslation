N, X, M = map(int, input().split())

S = {X : 1}

path = [X]

cnt = 1
ans = X
a = X
for i in range(2, N + 1):
    a = a * a % M
    if a in S:
        cnt = i - S[a]
        break
    S[a] = i

    ans += a
    path.append(a)

pre_len = S[a] - 1

Q, R = divmod(N - pre_len - 1, len(path) - pre_len)

pre = sum(path[:pre_len])
cycle = sum(path) - pre

ans = a
for _ in range(R):
    a = a * a % M
    ans += a

print(pre + Q * cycle + ans)
