N=int(input())
H = list(map(int,input().split()))
count = 1
maxi = H[0]

for i in range(1,N):
    if H[i] >= maxi:
        count += 1
        maxi = H[i]
print(count)