n = int(input())
s = input()
k = int(input())

sk = s[k-1]
anslis = [s[i] for i in range(n)]
ans = ""

for i in range(n):
    if s[i] != sk:
        anslis[i] = "*"

for i in range(n):
    ans = ans + str(anslis[i])

print(ans)