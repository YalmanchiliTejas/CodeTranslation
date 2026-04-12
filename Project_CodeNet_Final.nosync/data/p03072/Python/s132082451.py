n = int(input())
li = list(map(int,input().split()))
count = 1
for i in range(1,n):
    if li[i] >= max(li[:i]):
        count += 1
print(count)