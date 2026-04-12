N=int(input())
S=input()
K=int(input())

xyz = S[K-1]
cnt=""
for i in range(N):
    if S[i] != xyz:
        cnt += "*"
    else:
        cnt += xyz
print(cnt)
