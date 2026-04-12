N,*H = map(int, open(0).read().split())
#print(H)
L = 0

for i in range(N):
    if i == 0:
        L+=1
    elif max(H[0:i]) <= H[i]:
        L+=1
print(L)