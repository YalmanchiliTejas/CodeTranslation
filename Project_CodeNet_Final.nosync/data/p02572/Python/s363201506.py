

N = int(input())
A = list((input().split(" ")))

values = []
for i in range(N):
    values.append(int(A[i]))


suffixSumArray = values.copy()



for i in range(N-2,-1,-1):
    suffixSumArray[i] = suffixSumArray[i+1] + suffixSumArray[i]



sum = 0
for i in range(N-1):
    sum += (values[i] * suffixSumArray[i+1])

print(sum % (10 ** 9 + 7))