def make_dict(s):
    res = {}
    for v in s:
        if v in res:
            res[v] += 1
        else:
            res[v] = 1
    return res

n = int(input())
s = []
for i in range(n):
    s.append(input())

w_dict = make_dict(s[0])

for i in range(1, n):
    tmp_dict = make_dict(s[i])
    keys = list(w_dict.keys())
    for k in keys:
        if k in tmp_dict:
            w_dict[k] = min(w_dict[k], tmp_dict[k])
        else:
            w_dict.pop(k)

if w_dict:
    ans = ''
    for k in sorted(w_dict.keys()):
        ans += k * w_dict[k]
    print(ans)
else:
    print('')