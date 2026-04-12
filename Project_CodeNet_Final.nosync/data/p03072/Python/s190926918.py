n =int(input())
h =list(map(int ,input().split()))
k =0
count =0
for i in range(0 ,n):
    if k <= h[i]:
        count +=1
        k =h[i]
print(count)