N,K=map(int,input().split(" "))

if K == 0:
    print(N**2)
    exit()

b = K + 1
s = 0
while b <= N:
    c = N % b
    s += (N//b)*(b-K) + max(0,c-K+1)
    b += 1

print(s)