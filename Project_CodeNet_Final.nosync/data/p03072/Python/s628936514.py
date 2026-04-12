N = int(input())
H = list(map(int,input().split()))

c = 1
for i in range(1,N):
    if H[i]>= max(H[:i]):
        c = c+1
print(c)    