N = int(input())
A=list(map(int, input().split()))
B=[A[N-1]]
#print(B[0])
for i in range(len(A)-2):
    #print(i)
    b=B[i]+A[N-2-i]
    B.append(b)
#print(B)
total=0
for i in range(len(B)):
    total += A[i]*B[len(B)-1-i]

print(total%(10**9+7))