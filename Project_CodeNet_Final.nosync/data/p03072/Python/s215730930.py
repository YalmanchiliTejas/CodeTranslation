N = int(input())
H = list(map(int,input().split()))
canview = 0
for i in range(N):
    canview = (canview +  1 if H[i] == max(H[0:i+1]) else canview)
print(canview)