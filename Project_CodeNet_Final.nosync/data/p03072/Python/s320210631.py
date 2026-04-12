c = 0
mx = 0
n = int(input())
l = list(map(int,input().split()))
for i in range(len(l)):
    if(l[i]>=mx):
        c+=1
    mx = max(mx,l[i])
print(c)