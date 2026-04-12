n = int(input())
hight = list(map(int,input().split()))
cnt = 1
maxd = hight[0]

for i in range(n-1):
    if maxd <= hight[i+1]:
        cnt = cnt +1
        maxd = hight[i+1]
    else:
         continue
        
print(cnt)
