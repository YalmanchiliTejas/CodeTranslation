N = int(input())
A = sorted([int(input()) for _ in range(N)], reverse=True)
result = 0
if N % 2 == 0:
    k = [2]*((N-2)//2)
    k += [1]
    k += [-1]
    a = [-2]*((N-2)//2)
    k = k+a
    for a, keisu in zip(A, k):
        result += a*keisu
else:
    k = [2]*(N//2-1)
    k += [1]
    k += [1]
    a = [-2]*(N//2)
    k = k+a
    result1 = 0
    for a, keisu in zip(A, k):
        result1 += a*keisu
    k = [2]*(N//2)
    k += [-1]
    k += [-1]
    a = [-2]*(N//2-1)
    k = k+a
    result2 = 0
    for a, keisu in zip(A, k):
        result2 += a*keisu
    result = max(result1, result2)
print(result)