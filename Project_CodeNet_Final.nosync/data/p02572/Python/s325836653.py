N=input()
A=list(map(int,input().split()))
count1=0
count2=0
for a in A[0:]:
    count1=count1+a
    count2=count2+a**2

B=(count1**2-count2)//2
C=B%(10**9+7)
print(C)