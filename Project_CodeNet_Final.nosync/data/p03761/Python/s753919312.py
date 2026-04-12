n = int(input())
S = ['']*n
alphabet = 'abcdefghijklmnopqrstuvwxyz'
cnt = [[0]*n for _ in range(26)]
for i in range(n):
    S[i] = input()
    for j in range(26):
        cnt[j][i] = S[i].count(alphabet[j])
ans = ''
for i in range(26):
    ans += alphabet[i]*min(cnt[i])
print(ans)