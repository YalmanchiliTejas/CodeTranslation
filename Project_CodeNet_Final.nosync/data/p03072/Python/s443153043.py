N = int(input());
A = list(map(int,input().split()))

maxH = 0;
count = 0;
for i in range(N):
    if maxH <= A[i]:
        count+= 1
    maxH = max(maxH, A[i])


print(count)