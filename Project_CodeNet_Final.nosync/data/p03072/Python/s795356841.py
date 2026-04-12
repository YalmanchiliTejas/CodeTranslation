N = int(input())
H = list(map(int,input().split()))
tmp_m = 0
count = 0
for i in range(N):
    if tmp_m <= H[i]:
        tmp_m = H[i]
        count+=1
print(count)
