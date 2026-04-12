def main():
    N = int(input())
    A = list(map(int,input().split()))
    MOD = 10**9 +7

    S = 0
    for i in range(len(A)-1):
        tmp = 0
        for j in range(i+1,len(A)):
            tmp+=A[j]
        S+= (tmp%MOD * A[i])%MOD


    print(S%MOD)



from itertools import accumulate

m = 10**9 + 7

N,*A = map(int,open(0).read().split())

result = 0

b = [0]*N
b[0] = A[0]
for i in range(1,N):
    b[i]= b[i-1] + A[i]




for i in range (N-1):
    result += A[i]*(b[N-1]-b[i])
    result %= m
print(result)
