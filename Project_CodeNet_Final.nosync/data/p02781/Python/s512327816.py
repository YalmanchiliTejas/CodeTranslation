N = int(input())
K = int(input())

cmb = [[0]*(101) for _ in range(101)]
cmb[0][0] = 1
for i in range(1, 101):
    for j in range(i+1):
        if j == 0:
            cmb[i][j] = 1
            continue
        cmb[i][j] = cmb[i-1][j-1]+cmb[i-1][j]

S = str(N)
ans = 0
if K == len(S):
    for i in range(K):
        ans += (int(S[i])-1)*9**(K-i-1)
    ans += 1
else:
    for i in range(K, len(S)):
        ans += 9*cmb[i-1][K-1]*9**(K-1)
    if K == 1:
        ans += int(S[0])
    if K == 2:
        ans += (int(S[0])-1)*(len(S)-1)*9
        i = 1
        while i < len(S) and S[i] == "0":
            i += 1
        if i < len(S):
            ans += (len(S)-1-i)*9
            ans += int(S[i])
    if K == 3:
        ans += (int(S[0])-1)*cmb[len(S)-1][K-1]*9**(K-1)
        i = 1
        while i < len(S)-1 and S[i] == "0":
            i += 1
        flag = True
        if i < len(S)-1:
            ans += cmb[len(S)-i-1][2]*9**2
            ans += (int(S[i])-1)*(len(S)-i-1)*9
        else:
            flag = False
        i += 1
        while i < len(S) and S[i] == "0":
            i += 1
        if i < len(S) and flag:
            ans += (len(S)-i-1)*9
            ans += int(S[i])
print(ans)