N = int(input())
s = [input() for i in range(N)]
alpha = "abcdefghijklmnopqrstuvwxyz"
ans = ''
for i in alpha:
    min_ = float('Inf')
    for sj in s:
        cnt = 0
        for elem in sj:
            if elem == i:
                cnt += 1
        min_ = min(min_, cnt)
    ans += i * min_
print(ans)