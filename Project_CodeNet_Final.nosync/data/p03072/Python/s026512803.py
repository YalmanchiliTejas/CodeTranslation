n = int(input())
l = [int(i) for i in input().split()]
H = l[0]
cnt=1
for p in range(1,n,1):
    if H <= l[p]:
        cnt+=1
        H = l[p]
print(cnt)