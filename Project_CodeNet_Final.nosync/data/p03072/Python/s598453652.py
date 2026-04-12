n = int(input())
h = list(map(int,input().split()))
count = 0
for i in range(n):
    done = True
    for j in range(i):
        if h[j]>h[i]:
            done = False
    if done:
        count +=1
print(count)