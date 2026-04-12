import math
def C(a,b):
    return math.factorial(a) // (math.factorial(b)*math.factorial(a-b))

def count(N, K):
    if K == 0:
        return 1
    if N == 0:
        return 0
    keta = int(math.log10(N)) + 1
    if keta < K:
        return 0
    elif keta == K:
        if K == 1:
            return N
        elif K == 2:
            return (N//10 - 1) * 9 + N % 10
        else:
            return (N//100 - 1) * 81 + ((N//10)%10 - 1) * 9 + N % 10
    else:
        keta1 = (N//(10**(keta-1)))%10
        ans = C(keta - 1, K) * (9**K)
        ans += (keta1 - 1) * C(keta-1, K-1) * (9**(K-1))
        ans += count(N-(keta1*(10**(keta-1))), K-1)
        return ans

N = int(input())
K = int(input())
print(count(N,K))