n = int(input())
S = [input() for i in range(n)]
ans = ""
for i in range(97,123):
    min_count = 51
    for e in S:
        if e.count(chr(i)) < min_count:
            min_count = e.count(chr(i))
    ans += chr(i) * min_count
print(ans)