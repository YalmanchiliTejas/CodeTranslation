from collections import defaultdict
N = int(input())
cnt = defaultdict(int)
for c in input():
    cnt[c] += 1
for _ in range(N-1):
    tmp_cnt = defaultdict(int)
    for c in input():
        tmp_cnt[c] += 1

    for k, v in cnt.items():
        cnt[k] = min(cnt[k], tmp_cnt[k])
ans = ''
for k, v in cnt.items():
    ans += k*v
print(''.join(sorted(ans)))
