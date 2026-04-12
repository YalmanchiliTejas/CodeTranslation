N = int(input())
H = [int(i) for i in input().split()]
count=1
for i in range(1,N):
    Max = max(H[:i])
    if H[i]>=H[i-1] and Max<=H[i]:
        count+=1
print(count)