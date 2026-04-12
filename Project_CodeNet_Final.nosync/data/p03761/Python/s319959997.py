N = int(input())
S = [input() for _ in range(N)]

from collections import Counter, defaultdict

alpha = set([chr(c) for c in range(ord("a"), ord("z") + 1)])

for s in S:
    alpha &= set(list(s))

if not alpha:
    print()
else:
    alpha = sorted(list(alpha))
    cnt = defaultdict(int)
    for s in S:
        for k,c in Counter(s).items():
            if k in alpha:
                if cnt[k] == 0:
                    cnt[k] = c
                cnt[k] = min(cnt[k], c)
    cnt_sorted = sorted(cnt.items(), key=lambda x:x[0])

    ans = ""
    for a,c in cnt_sorted:
        ans += a * c
    
    print(ans)