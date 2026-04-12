N = int(input())
X = list(map(int,input().split()))
S = X[:]
S.sort()
C1 = S[(N//2)-1]
C2 = S[N//2]
for x in X:
    if x >= C2:
        print(C1)
    else:
        print(C2)