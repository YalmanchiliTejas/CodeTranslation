n = int(input())
l = list(map(int,input().split()))

maxx = -1
cnt = 0
for i in range(len(l)):
    if l[i] >= maxx:
        maxx = l[i]
        cnt+=1
print(cnt)