N = int(input())
a=list(map(int,input().split()))

Tail = a[N-1]
R = 0
m = 7+10**9
for i in range(N-2,-1,-1):

    R = (R+a[i]*Tail)%m
    Tail +=a[i]
    
print(R)
