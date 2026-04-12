n = int(input())
lst = [input() for _ in range(n)]
ret = []
for c in "abcdefghijklmnopqrstuvwxyz":
    cnt = 50
    for s in lst:
        cnt = min(cnt, s.count(c))
    ret.append(c * cnt)
print("".join(ret))
