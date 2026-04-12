N = int(input())
Data = []
for _ in range(N):
    Data.append([0]*26)

for i in range(N):
    S = input()
    for s in S:
        p = ord(s)-ord('a')
        Data[i][p] += 1

ans = ''
for i in range(26):
    minn = 10**10
    for n in range(N):
        minn = min(minn,Data[n][i])
    ans += (chr(ord('a')+i) * minn)  

print(ans)
