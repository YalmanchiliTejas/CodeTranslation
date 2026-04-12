H, W = map(int,input().split())
s = []
for k in range(H):
    s.append(input())
m1 = float("inf")
M1 = 0
m2 = float("inf")
M2 = 0
for k in range(H):
    for l in range(W):
        if s[k][l] == "B":
            m1 = min(m1,k+l)
            M1 = max(M1,k+l)
            m2 = min(m2,W-1-l+k)
            M2 = max(M2,W-1-l+k)
print(max(M1-m1,M2-m2))

