N = int(input())
A = list(map(int, input().split()))
#print(A)

total = 0
left = 0
sum = sum(A)
#print(end)

for i in range(N - 1):
    #print(i, A[i])
    left = left + A[i]
    #start = i + 1
    #for j in range(start, N):
        #print(i, j)
        #sum = sum + A[j]
    #print(A[i], sum)
    right = sum - left
    #print(i, left, right, A[i])
    total = (total + A[i] * right) % 1000000007

print(total)