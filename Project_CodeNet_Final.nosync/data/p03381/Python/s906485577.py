N = int(input())
X = list(map(int, input().split()))
sort_X = sorted(X)       
v1 = sort_X[N//2-1]
v2 = sort_X[N//2]
for i in range(N):
    if(X[i] <= v1):
         print(v2)
    else:     
         print(v1)