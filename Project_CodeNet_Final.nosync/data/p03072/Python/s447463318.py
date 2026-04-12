n = int(input())
Hotel = list(map(int, input().split()))
Hotel = [0] + Hotel
cnt = 0
for i in range(1, n+1):
    look = Hotel[i]
    for j in range(i):
        if look >= Hotel[j]:
            continue
        else:
            break
    else:
        cnt += 1
print(cnt)