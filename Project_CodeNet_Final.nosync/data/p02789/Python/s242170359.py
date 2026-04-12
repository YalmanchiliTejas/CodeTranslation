num = list(map(int, input().split()))
if 1 <= num[0] <= 100 and 0 <= num[1] <= num[0]:
    if num[0] <= num[1]:
        print('Yes')
    else:
        print('No')
