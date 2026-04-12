n = int(input())
h = list(map(int,input().split()))
x = 0
for i in range(n):
    for j in range(i+1):
        if h[j]>h[i]:
            break
    else:
        x +=1

print(x)