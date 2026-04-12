n = int(input())
s = [input() for _ in range(n)]
for i in range(97, 123):
    cnt = 50
    for j in s:
        cnt = min(cnt, j.count(chr(i)))
    print(chr(i) * cnt, end='')
