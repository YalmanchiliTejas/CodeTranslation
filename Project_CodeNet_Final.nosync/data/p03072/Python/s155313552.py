N=int(input())
Hn=list(map(int,input().split()))
c = 1
for i in range(1, N):
    for j in range(0, i):
        if Hn[j] > Hn[i]:
            break
    else:
        c += 1
print(c)