N = int(input())
A = sorted([int(input()) for i in range(N)])
Ami = A[:N//2]
Ama = A[N//2:][::-1]
Ami2 = A[:(N+1)//2]
Ama2 = A[(N+1)//2:][::-1]

if N%2 == 1:
    ans = -2*sum(Ami)
    ans += 2*sum(Ama[:-2]) + Ama[-1]+Ama[-2]
    ans2 = -2*sum(Ami2[:-2]) - Ami2[-1]-Ami2[-2]
    ans2 += 2*sum(Ama2)
    print(max(ans2,ans))
else:
    ans = -2*sum(Ami[:-1]) - Ami[-1]
    ans += 2*sum(Ama[:-1]) + Ama[-1]
    print(ans)