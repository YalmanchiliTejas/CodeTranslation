n = int(input())
arr = list(map(int, input().split(' ')))

maxi = arr[0]
ans = 0
for num in arr:
    if maxi > num:
        pass
    else:
        ans += 1
        maxi = num

print(ans) 