a = int(input())
ar = list(map(int,input().split(" ")))
count = 1
for i in range(1,a):
    br = ar[:i+1]
    if ar[i] >= max(br):
        count += 1
print(count)