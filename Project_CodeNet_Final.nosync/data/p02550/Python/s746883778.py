N,X,M = map(int,input().split())

data = [X for i in range(M+1)]
val = set([X])

start = -1
period = -1
for i in range(1,M+1):
    data[i] = pow(data[i-1],2,M)
    if data[i] in val:
        for j in range(0,i):
            if data[j]==data[i]:
                start = j
                period = i-j
                break
        break
    else:
        val.add(data[i])

if N<=M:
    print(sum(data[:N]))
else:
    res = sum(data[:start])

    backet = sum(data[start:start+period])
    Q = (N - start) // period
    R = (N- start) % period

    res += backet*Q + sum(data[start:start+R])
    print(res)
