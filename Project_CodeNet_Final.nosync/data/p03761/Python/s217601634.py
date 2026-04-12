n = int(input())
S = []


cnt_min = [50 for i in range(26)]

for i in range(n):
    cnt = [0 for i in range(26)]
    s = list(input())
    s.sort()
    for i in s:
        cnt[ord(i) - ord("a")] += 1

    for i in range(26):
        cnt_min[i] = min(cnt_min[i], cnt[i])


for i in range(26):
    for j in range(cnt_min[i]):
        print(chr(ord("a") + i), end = "")
print()