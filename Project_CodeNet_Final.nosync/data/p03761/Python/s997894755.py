from collections import Counter

N = int(input())
cs = []
for _ in range(N):
    s = input()
    c = Counter(s)
    cs.append(c)
#     print(c)

ans = ""    
for alpha in list("abcdefghijklmnopqrstuvwxyz"):
    min_cnt = 50
    for c in cs:
        min_cnt = min(min_cnt, c[alpha])
    ans += alpha*min_cnt
print(ans)
