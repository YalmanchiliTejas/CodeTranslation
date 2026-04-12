n, x, m = map(int, input().split())

period = 0


UNDEF = -1
last_idx = [UNDEF] * (m + 1)


ans = 0


def get_start_and_loop(n, x, m):
    first = x
    cur = first
    i = 0
    vals = []
    for i in range(n):
        if last_idx[cur] != UNDEF:
            return last_idx[cur], sum(vals[: last_idx[cur]]), i - last_idx[cur], sum(vals[last_idx[cur]: ]), cur
        last_idx[cur] = i
        vals.append(cur)
        cur = (cur * cur) % m
        i += 1
    return n, sum(vals), 1, 0, 0

start, start_sum, period, period_sum, cur = get_start_and_loop(n, x, m)

ans = start_sum
n -= start
ans += n // period * period_sum
n %= period

for i in range(n):
    ans += cur
    cur = (cur * cur) % m

print(ans)









