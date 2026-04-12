N = int(input())
A = list(map(int,input().split(" ")))
m = float('-inf')
count = 1
for i in range(1,N):
    m = max(m,A[i-1])
    if A[i]>=m: count += 1
print(count)