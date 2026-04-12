N = int(input())
S = input()
K = int(input())

tar = S[K-1]
_ = ""
for i in range(N):
    if S[i] == tar:
        _ += tar
    else:
        _ += "*"

print(_)