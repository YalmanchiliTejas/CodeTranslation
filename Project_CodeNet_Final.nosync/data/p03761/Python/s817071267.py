N = int(input())
S = []
for i in range(N):
    S.append(input())
    
ALPHA = "abcdefghijklmnopqrstuvwxyz"

ans = ""
for a in ALPHA:
    count = 50
    for s in S:
        if s.count(a) < count:
            count = s.count(a)
    
    ans += a*count
    
print(ans)