n = int(input())
h = list(map(int, input().split()))
tall = 0
count = 0
for i in range(0,n):
    if ( tall <= h[i]):
        count +=1
        tall = h[i]
print(count)