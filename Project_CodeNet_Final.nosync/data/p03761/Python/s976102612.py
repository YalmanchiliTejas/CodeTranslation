from collections import defaultdict
n = int(input())
cnt = defaultdict(int)
for s in input():
    cnt[s] += 1

for _ in range(n-1):
    tmp = defaultdict(int)
    for s in input():
        tmp[s] += 1
    for k in cnt.keys():
        cnt[k] = min(cnt[k], tmp[k])

ans = []
for k, v in cnt.items():
    ans.extend([k]*v)
print(''.join(sorted(ans)))
