import sys
n = int(input())
h = list(map(int,input().split()))
cnt = 0
state = 1
for i in range(n):
    for j in range(i+1):
        if h[i]<h[j]:
            state = 0
            break
        else:
            state = 1
    if state == 1:
        cnt+=1
print(cnt)