N, T, E = map(int, input().split())
x = [int(x) for x in input().split()]
Time = list(range(T-E,T+E+1,1))

time = []
for i in range(N):
    t = []
    for j in range(len(Time)):
        if Time[j]%x[i]==0:
            t.append(1)
    if 1 in t:
        time.append(1)
    else:
        time.append(0)

if sum(time)==0:
    print(-1)
else:
    index = time.index(1)
    print(index+1)
