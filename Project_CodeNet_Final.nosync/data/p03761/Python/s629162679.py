N = int(input())
S = []
for i in range(N):
    S.append(input())

alfa = [chr(i) for i in range(97,97+26)]
counter = [1000000 for i in range(26)]

for s in S:
    for i in range(26):
        counter[i] = min(s.count(alfa[i]), counter[i])

ans = ''
for i in range(26):
    for j in range(counter[i]):
        ans += alfa[i]

print(ans)