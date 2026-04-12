N = int(input())

A = list(map(int,input().split()))

S = [0]*N
S[0] = A[0]
S[1] = A[1]

for i in range(2,N):
    S[i] = S[i-2] + A[i]

if N%2 == 0:
    ans = max(S[-1],S[-2])
    for i in range(N):
        if i % 2 == 0:
            ans = max(ans,S[i]+S[-1]-S[i+1])
    
    print(ans)

else:
    M = A[0]
    for i in range(1,N//2+1):
        M = min(M,A[2*i])

    mss = - M
    s = - A[0]
    for i in range(N//2):
        s += A[2*i+1] - A[2*i+2]
        if s < 0:
            s = - A[2*i+2]
        elif mss < s:
            mss = s
        #print(i,mss)
    
    mss2 = - M
    t = - A[-1]
    for i in range(1,N//2+1):
        t += A[-2*i] - A[-2*i-1]
        if t < 0:
            t = - A[-2*i-1]
        elif mss2 < t:
            mss2 = t
    
    p = S[-2]
    for i in range(1,N):
        if i % 2 == 1:
            p = max(p,S[i]+S[-1]-S[i+1])
    
    print(max(S[-1]+mss,S[-1]+mss2,p))

###
#print(S)
#print(M)
###