N,S,K = [input() for x in [0,1,2]]

c = S[int(K)-1]

ans = ""

for char in S:
    if char == c:
        ans += c
    else:
        ans += '*'
print(ans)
