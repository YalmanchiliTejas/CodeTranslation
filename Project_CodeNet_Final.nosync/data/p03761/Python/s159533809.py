N = int(input())
ordA = ord("a")
mozilist = [0] * 26
for k in range(26):
    mozilist[k] = [0]*N
for i in range(N):
    S = input()
    for j in range(len(S)):
        mozilist[ord(S[j]) - ordA][i] += 1
ans = ""
for p in range(26):
    numofthealphabet = min(mozilist[p])
    ans += chr(ordA + p) * numofthealphabet
print(ans)
