from collections import Counter, defaultdict
n = int(input())
s = [input() for i in range(n)]

cnt = defaultdict(lambda :[0, 0])
for S in s:
    temp = Counter(S)
    for key, val in temp.items():
        if cnt[key] == [0, 0]:
            cnt[key] = [val, 1]
            continue
        if cnt[key][0] > val:cnt[key][0] = val
        cnt[key][1] = cnt[key][1] + 1

ans = []
for key, val in cnt.items():
    if val[1] == n:
        ans += key * val[0]
print(*sorted(ans), sep='')
#print(cnt)