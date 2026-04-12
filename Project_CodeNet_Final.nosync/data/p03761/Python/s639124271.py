import collections

n = int(input())

ans_s = collections.Counter(input())
for i in range(1, n):
    loss_key = list(ans_s.keys())
    s = collections.Counter(input())
    key = s.keys()
    for k in key:
        ans_s[k] = min(ans_s[k], s[k])
        if k in loss_key:
            loss_key.remove(k)
    for k in loss_key:
        ans_s[k] = 0

ans = ""
for key in ans_s.keys():
    ans += key * ans_s[key]
print("".join(sorted(ans)))