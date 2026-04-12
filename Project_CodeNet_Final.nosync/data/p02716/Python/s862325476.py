n = int(input())
a = list(map(int, input().split()))
choice = n // 2

dic1 = {0:0}
dic2 = {0:0, 1:a[0]}

for i in range(1, n):
    mini = choice - (n-i+1)//2
    new = {}
    for j in range(mini, (i+2)//2+1):
        if j == 0:
            new[j] = 0
            continue
        if j in dic2:
            new[j] = max(dic2[j], dic1[j-1]+a[i])
        else:
            new[j] = dic1[j-1]+a[i]
    dic1 = dic2
    dic2 = new

print(dic2[choice])