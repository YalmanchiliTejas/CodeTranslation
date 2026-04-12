N = int(input())
H = list(map(int,input().split()))
pre = H[0]
count = 1
for i in range(N-1):
    if pre <= H[i+1]:
        count += 1
        pre = H[i+1]
print(count)