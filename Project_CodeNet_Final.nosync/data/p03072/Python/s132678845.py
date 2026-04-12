num = int(input())
arr = list(map(int, input().split()))

count=0

now_max = arr[0]

for v in arr:
    if v>=now_max:
        count += 1
        now_max = v

print(count)