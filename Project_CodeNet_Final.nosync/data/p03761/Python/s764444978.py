n = int(input())
S = [100]*26
count = [0]*26
alpha = [chr(i) for i in range(97, 97+26)]

for i in range(n):
    a = input()
    for j in range(26):
        count[j] = a.count(alpha[j])
    S = [min(a,b) for a,b in zip(S,count)]

ans = ""

for i in range(26):
    ans = ans + alpha[i]*S[i]
print(ans)