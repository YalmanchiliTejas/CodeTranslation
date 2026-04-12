N, X = map(int, input().split())
L, C = [1], [1]
for n in range(1,N+1):
    L.append(2*L[-1]+3)
    C.append(2*C[-1]+1)
C.append(0)
step = 0
res = 0
for i in reversed(range(N+1)):
    if X<=step+L[i]//2:
        step+=1
    elif X>step+L[i]//2+1:
        step += L[i]//2+1
        res += C[i-1]+1
    else:
        res += C[i-1]+1
        break
print(res)