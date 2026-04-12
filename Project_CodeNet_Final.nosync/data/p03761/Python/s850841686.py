n = int(input())
S = "abcdefghijklmnopqrstuvwxyz"
C = [[0 for k in range(n)] for l in range(26)]
for k in range(n):
    t = input()
    for e in t:
        C[ord(e)-97][k] += 1
ans = ""
for k in range(26):
    ans += S[k]*min(C[k])
print(ans)
