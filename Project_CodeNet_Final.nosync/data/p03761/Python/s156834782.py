N = int(input())

S = [50]*26

for i in range(N):
    s = [0]*26
    for item in input():
        s[ord(item)-97] += 1
    for i in range(26):
        S[i] = min(S[i], s[i])

ans = ""
for i in range(26):
    ans += chr(97+i)*S[i]
print(ans)

