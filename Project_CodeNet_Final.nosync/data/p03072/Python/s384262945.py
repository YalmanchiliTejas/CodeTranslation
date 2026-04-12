n = int(input())
hlist = list(map(int,input().split()))
count = 1
max = hlist[0]
for i in range(1,n):
    if hlist[i] >= max:
        max = hlist[i]
        count += 1
print(count)