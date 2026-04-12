N = int(input())
a = list(map(int, input().split()))
res = 1

for i in range(1,N):
    if a[i] >= max(a[0:(i)]):
        res +=1
    
print(res)


