N=int(input())
A = list(map(int, input().split()))
# for i in range(N):
#     a=map(int,input().split())
#     A.append(a) 

x=0
B=A[0]
for i in range(N):
    if B<=A[i]:
        x+=1
        B=A[i]

print(x)



