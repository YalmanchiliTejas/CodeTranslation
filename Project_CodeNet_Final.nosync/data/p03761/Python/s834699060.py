n = int(input())
MinNum = [10**4 for i in range(26)]
Alphabet = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", \
    "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]
for i in range(n):
    s = input()
    for j in range(26):
        MinNum[j] = min(MinNum[j], s.count(Alphabet[j]))

ans = ""
for i in range(26):
    if MinNum[i] > 0:
        ans += Alphabet[i] * MinNum[i]

print(ans)