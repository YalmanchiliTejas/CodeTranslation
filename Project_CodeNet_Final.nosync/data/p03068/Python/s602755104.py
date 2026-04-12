import sys

N = int(sys.stdin.readline())
S = sys.stdin.readline().rstrip()
K = int(sys.stdin.readline())


temp = S[K-1]

ans = ""
for i in range(len(S)):
    if temp == S[i]:
        ans = ans + temp
    else:
        ans = ans + "*"

print(ans)