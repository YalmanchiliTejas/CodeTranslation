from collections import Counter

n = int(input())
counter = Counter(input())
for _ in range(n - 1):
    counter2 = Counter(input())
    for k in counter.keys():
        if counter2[k] > 0:
            counter[k] = min(counter[k], counter2[k])
        else:
            counter[k] = 0

ans = ''
for k in sorted(counter.keys()):
    ans += k * counter[k]

print(ans)
