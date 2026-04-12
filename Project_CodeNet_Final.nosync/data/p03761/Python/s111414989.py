N = int(input())
char_cnt = {}
check = {}

for c in input():
    if c in char_cnt:
        char_cnt[c] += 1
    else:
        char_cnt[c] = 1
        check[c] = 1

for i in range(N - 1):
    s = input()
    cnt = {}
    for c in s:
        if c in cnt:
            cnt[c] += 1
        else:
            cnt[c] = 1
    for c, n in cnt.items():
        if c in char_cnt:
            char_cnt[c] = min(char_cnt[c], cnt[c])
            check[c] += 1

ans = ""
for c, n in sorted(char_cnt.items(), key=lambda x:x[0]):
    if check[c] == N:
        for i in range(n):
            ans += c
print(ans)