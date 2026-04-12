from string import ascii_lowercase
def count(x):
    res = {c:0 for c in ascii_lowercase}
    for d in x:
        res[d] += 1
    return res

n = int(input())
maxs = {c:float('inf') for c in ascii_lowercase}
for _ in range(n):
    for k, v in count(input()).items():
        maxs[k] = min(maxs[k], v)

ans = ''
for k, v in sorted(maxs.items(), key=lambda x: x[0]):
    ans += v*k
print(ans)