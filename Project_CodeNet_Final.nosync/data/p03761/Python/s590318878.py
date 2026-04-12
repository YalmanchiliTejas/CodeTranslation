N=int(input())
A=[60]*30
T=' '
B=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
for i in range(N):
    S=input()
    for k in range(26):
        count=S.count(B[k])
        if A[k]>=count:
            A[k]=count

for i in range(26):
    for k in range(A[i]):
        T=T+B[i]
print(T.strip())