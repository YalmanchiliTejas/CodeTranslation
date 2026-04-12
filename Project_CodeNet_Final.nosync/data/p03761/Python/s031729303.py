N = int(input())
S = [input() for _ in range(N)]

alphabet = [chr(i) for i in range(97, 97 + 26)]
ans = ""

for a in alphabet:
    c_min = 50
    for i in range(N):
        c = S[i].count(a)
        c_min = min(c, c_min)
    ans += a * c_min

print(ans)
