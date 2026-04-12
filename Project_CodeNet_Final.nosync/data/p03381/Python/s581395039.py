import copy
N = int(input())
x_original = list(map(int,input().split()))
x = sorted(copy.copy(x_original))
n = int(N/2)
for i in range(N):
    if(x_original[i]>=x[n]):
        print(x[n-1])
    else:
        print(x[n])
