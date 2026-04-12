n = int(input())
a = 'abcdefghijklmnopqrstuvwxyz'
S = []
for _ in range(n):
    S.append(input().strip())

for c in a:
    cnt = 50
    for s in S:
        cnt_s = s.count(c)

        if cnt_s < cnt:
            cnt = cnt_s
    print(c * cnt, end="")
print()