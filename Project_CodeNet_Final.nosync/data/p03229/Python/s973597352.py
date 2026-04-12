N = int(input())
As = []
for i in range(N):
    As.append(int(input()))
As.sort()
if N%2 == 0:
    s = 0
    for i in range(N):
        if i < N/2:
            s -= 2*As[i]
        else:
            s += 2*As[i]
    s = s + As[int(N/2)-1] -As[int(N/2)]
    print(s)
else:
    s1, s2 = 0, 0
    for i in range(N):
        if i < N//2 -1:
            s1 -= 2*As[i]
        elif N//2-1 <= i <=N//2 :
            s1 -= As[i]
        else:
            s1 +=  2*As[i]
        if i < N//2:
            s2 -= 2*As[i]
        elif N//2 <= i <= N//2 +1:
            s2 += As[i]
        else:
            s2 += 2*As[i]
    print(max(s1, s2))
