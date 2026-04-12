from collections import Counter, defaultdict
n = int(input())
S = []
for i in range(n):
    S.append(Counter(input()))
dic = defaultdict(int)
ans = ''
for i in [chr(ord('a') + i) for i in range(26)]:
    ls = []
    for x in S:
        if i in x:
            ls.append(x[i])            
    if len(ls) == n:
        dic[i] = min(ls)
ans = ''
for i in [chr(ord('a') + i) for i in range(26)]:
    ans += i*dic[i]
print(ans)