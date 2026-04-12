def chc(H,now):
    if(now == 0):
        return True
    else:
        for i in range(now):
            if(H[i]>H[now]):
                return False
        return True


N = int(input())
H = list(map(int,input().split()))

counter = 0
for i in range(N):
    if(chc(H,i)):
        counter += 1

print(counter)

