def sarch(s):
    key = 0
    for i in range(len(s)):
        if s[i] == "#":
            key = i
    return key

def judge(s):
    key = 0
    for i in s:
        if i == "#":
            key = 1
            break
    return key

H, W = map(int, input().split())
A = [["0" for i in range(W)] for j in range(H)]
for i in range(H):
    S = input()
    for j in range(W):
        A[i][j] = S[j]
key = "Possible"
for i in range(1, H):
    if judge(A[i][0:sarch(A[i - 1])]) != 0:
        key = "Impossible"
        break
print(key)