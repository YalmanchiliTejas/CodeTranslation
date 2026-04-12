N, X, M = map(int, input().split())
cnt = [0] * M
cnt[X] = 1
start = -1
seq = [X]
for i in range(1, N):
    X = X * X % M
    if cnt[X] > 0:
        start = X
        break
    seq.append(X)
    cnt[X] += 1

if start < 0:
    print(sum(seq))
    exit()

cycle_start_idx = seq.index(start)
header = seq[:cycle_start_idx]
cycle = seq[cycle_start_idx:]
in_cycle_N = N - len(header)
q, r = divmod(in_cycle_N, len(cycle))
ans = sum(header) + sum(cycle) * q + sum(cycle[:r])
print(ans)
