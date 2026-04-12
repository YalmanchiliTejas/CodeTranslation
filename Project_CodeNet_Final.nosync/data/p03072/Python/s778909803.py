num=int(input())
Hn=input().split()
HMax=0
count=0

for i in range(num):

    if int(Hn[0]) <= int(Hn[i]):
        if HMax   <= int(Hn[i]):
            count += 1
            HMax=int(Hn[i])

print(count)
