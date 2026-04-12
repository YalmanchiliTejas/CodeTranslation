n = int(input())
h = [int(i) for i in input().split()]
cnt = 0
for i in range(n):
    for j in range(i):
        if h[j] > h[i]:
            break
        elif i-j==1:
            cnt+=1
print(cnt+1)