N = input()

data = [list(raw_input()) for i in range(N)]

alpha = [chr(i) for i in range(97,97+26)]
cnt = [[0 for i in range(26)] for i in range(N)]

for i in range(N):
    for j in range(26):
        cnt[i][j] = data[i].count(alpha[j])


ans = ''
for i in range(26):
    mini = 10000
    for j in range(N):
        mini = min(mini,cnt[j][i]) 
    ans += alpha[i]*mini

print ans