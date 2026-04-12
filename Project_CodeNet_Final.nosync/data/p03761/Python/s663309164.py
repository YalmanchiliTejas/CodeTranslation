n = int(input())
alpha = [0 for i in range(26)]
s = input()
for j in range(len(s)):
    alpha[ord(s[j])-ord("a")] += 1
for i in range(1, n):
    s = input()
    tmpAlpha = [0 for i in range(26)]
    for j in range(len(s)):
        tmpAlpha[ord(s[j]) - ord("a")] += 1
    for j in range(len(alpha)):
        alpha[j] = min(alpha[j], tmpAlpha[j])
out = ""
for i in range(len(alpha)):
    for j in range(alpha[i]):
        out += chr(i + ord("a"))
print(out)