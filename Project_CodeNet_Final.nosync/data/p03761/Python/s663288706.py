N = int(input())
X = [50] * 26
for _ in range(N):
    S = input()
    for i in range(26):
        X[i] = min(X[i], S.count(chr(97+i)))

ANS = ""
for i in range(26):
    ANS += chr(97+i) * X[i]
print(ANS)