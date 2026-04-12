n = int(input())

cnt = [[0] * n for _ in range(26)]
for i in range(n):
    s = input()
    for c in s:
        cnt[ord(c) - ord('a')][i] += 1

for i in range(26):
    for _ in range(min(cnt[i])):
        print(chr(ord('a')+i), end='')