N = int(input())
S = [input() for _ in range(N)]

alp = [chr(i) for i in range(97,123)]

ans = ""
for al in alp :
    count = 10**10
    for sen in S :
        count = min(count, sen.count(al))
    ans += al * count

print(ans)
