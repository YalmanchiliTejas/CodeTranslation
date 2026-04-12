N=int(input())
S=input()
K=int(input())

moji=S[K-1]
S_ok=""
for i in range(N):
    now_moji=S[i]
    if now_moji==moji:
        S_ok=S_ok+now_moji
    else:
        S_ok=S_ok+"*"

print(S_ok)


