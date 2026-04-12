n = int(input())
S = [100] * 26
alphabet = 'abcdefghijklmnopqrstuvwxyz'
alpha_list = list(alphabet)

for i in range(n):
    s = input()
    for i in range(26):
        c = s.count(alpha_list[i])
        S[i] = min(S[i], c)

ans = ''

for i in range(26):
    for j in range(S[i]):
        ans += alpha_list[i]

print(ans)