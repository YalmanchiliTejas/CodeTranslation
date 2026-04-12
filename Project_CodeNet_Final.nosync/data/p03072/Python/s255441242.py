n = int(input())
h = list(map(int,input().split()))

re = 1
M = h[0]

for i in range(1,n):
    if M <= h[i]:
        re += 1
    M = max(M,h[i])
    
print(re)