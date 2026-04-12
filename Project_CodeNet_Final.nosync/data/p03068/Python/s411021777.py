N = int(input())
S = input()
K = int(input())

s = S[K-1]
list_S = list(S)

for i in range(N):
    if list_S[i] != s:
        list_S[i] = '*'

ans = "".join(list_S)
print(ans)