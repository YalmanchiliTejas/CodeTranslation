N = int(input())

L = []
for i in range(N):
    n = int(input())
    L.append(n)
    
L = sorted(L)
ans = []

if N % 2 == 0:
    A1 = L[0: N //2]
    A2 = L[N // 2:]
    ans.append(2 * sum(A2[1:]) + A2[0] - (2 * sum(A1[:-1]) + A1[-1]))
    
    A1 = L[0: N // 2]
    A2 = L[N // 2:]
    ans.append(2 * sum(A2[1:]) + A2[0] - (2 * sum(A1[:-1]) + A1[-1]))
    
    print(max(ans))
    
else:
    A1 = L[0: N // 2 + 1]
    A2 = L[N // 2 + 1:]
    ans.append(2 * sum(A2) - (2 * sum(A1[0: -2]) + A1[-1] + A1[-2]))
    
    A1 = L[0: N // 2]
    A2 = L[N // 2:]
    
    ans.append((2 * sum(A2[2:]) + A2[0] + A2[1]) - 2 * sum(A1))
    print(max(ans))