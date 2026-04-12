KK=10 ** 9 + 7
N = int(input())
A = list(map(int, input().split()))
X=0
K=sum(A) %KK
for x in A:
    K-= x 
    X+=K*x
    X%=KK

print(X)