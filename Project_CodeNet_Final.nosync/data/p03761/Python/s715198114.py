import collections 
n = int(input())
d = collections.Counter(input())
for _ in range(n-1):
    s = input()
    cnt = collections.Counter(s)
    for k,v in cnt.items():
        de = d.get(k,False)
        if de:
            d[k] = min(de,cnt[k])
    for k,v in d.items():
        if not cnt.get(k,False):
            d[k] = 0

ans = ''
for k,v in sorted(d.items()):
    ans += k*v
print(ans)
