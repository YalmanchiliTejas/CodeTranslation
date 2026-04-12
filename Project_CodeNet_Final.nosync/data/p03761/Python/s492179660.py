alpha_cnt = [100 for _ in range(26)]

for _ in range(int(input())):
    cnt_sub = [0 for _ in range(26)]
    for ss in input():
        pos = ord(ss) - ord("a")
        cnt_sub[pos] += 1
    for i in range(26):
        alpha_cnt[i] = min(alpha_cnt[i], cnt_sub[i])

ans = ""
for i in range(26):
    num = ord("a") + i
    ans += chr(num) * alpha_cnt[i]
print(ans)
    