n = int(input())
s = [0] * n
for i in range(n):
    s[i] = list(input())

char = list(set(s[0]))
for i in range(n):
    char = set(char) & set(s[i])

char = sorted(list(char))
cnt = [[0] * len(char) for _ in range(n)]
for i in range(n):
    for j in range(len(s[i])):
        for k in range(len(char)):
            if s[i][j] == char[k]:
                cnt[i][k] += 1

min_cnt = [50] * len(char)
for i in range(n):
    for j in range(len(char)):
        min_cnt[j] = min(min_cnt[j], cnt[i][j])

ans = ''
for i in range(len(char)):
    ans += char[i] * min_cnt[i]
print(ans)