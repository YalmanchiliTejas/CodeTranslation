n = int(input())
h = list(map(int, input().split()))
cnt =1
max_h=h[0]
for i in range(1,n):
    if max_h<=h[i]:
        cnt+=1
        max_h=h[i]
        #print(h[i])
print(cnt)