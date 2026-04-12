n = int(input())
S = []
al = [chr(ord('a') + i) for i in range(26)] 
for i in range(n):
    s = input()
    S.append(s)
ans = ''
for a in al:
    m = 50
    for i in range(n):
        if S[i].count(a) < m:
            m = S[i].count(a) 
    ans += a*m
print(ans)