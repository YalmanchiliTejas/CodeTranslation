N = int(input())
A = list(map(int,input().split()))

count = 0
flag = True

while flag:
    c = [0]*N
    for i in range(N):
        c[i] = A[i]//N
        A[i] %= N
    S = sum(c)
    flag = False
    for i in range(N):
        A[i]+=S-c[i]
        if A[i]>=N:
            flag=True
    count += S

print(count)