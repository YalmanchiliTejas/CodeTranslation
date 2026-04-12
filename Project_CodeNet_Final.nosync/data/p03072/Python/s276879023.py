N = int(input())
H = [int(x) for x in input().split()]

ans=0
MAX_H=H[0]

for i in range(N):
    if H[i] >= MAX_H:
        ans+=1
        MAX_H = H[i]
print(ans)