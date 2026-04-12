from collections import Counter, defaultdict
n = int(input())
lc = [chr(i) for i in range(97, 97+26)]
ans_dict = Counter(input())

for _ in range(n-1):
    S = input()
    tmp = {k:0 for k in lc}
    for s in S:
        tmp[s] += 1

    for k in tmp.keys():
        try:
            ans_dict[k] = min(ans_dict[k], tmp[k])
        except:
            pass

ans = ''
for k, v in sorted(ans_dict.items()):
    ans += k * v
print(ans)