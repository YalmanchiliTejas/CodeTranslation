N = int(input())
S = input()
K = int(input())
ans = ["*"]*N
SK = S[K-1]
for i in range(N):
    if SK == S[i]:
        ans[i] = SK
for i in ans:
    print(i,end="")
