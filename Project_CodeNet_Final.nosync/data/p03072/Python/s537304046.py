import sys
#sys.exit()
#sorted( ,reverse=True)
N = int(input())
#S,T = map(int, input().split())
H = list(map(int, input().split()))
#print(N)
#print(S,T)
#print(A)
ans = 0
max = H[0]
for h in H:
    if h >= max:
        ans += 1
        max = h
print(ans)
    