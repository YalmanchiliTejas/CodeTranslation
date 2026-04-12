n = int(input())
s = list(map(int,input().split()))
cnt = 1
for i in range(n-1,0,-1):
    result = True
    for j in range(i-1,-1,-1):
        if s[j] > s[i]:
            result = False
            break
    if result:
        cnt +=1
print(cnt)