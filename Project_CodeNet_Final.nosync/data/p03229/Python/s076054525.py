#C問題
N = int(input())
A = [int(input()) for i in range(N)]
A.sort(reverse=True)

p = 0
n = 0
if N%2 == 0:
    MAX = 0
    for i in range(N):
        if i < (N//2):
            if i == (N//2)-1:
                p+=A[i]
            else:
                p+=A[i]*2
        else:
            if i == (N//2):
                n+=A[i]
            else:
                n+=A[i]*2
    MAX = max(MAX,p-n)
else:
    MAX = 0
    for i in range(N):
        if i <= (N//2):
            if i == (N//2) or i == (N//2)-1:
                p+=A[i]
            else:
                p+=A[i]*2
        else:
            n+=A[i]*2
    MAX = max(MAX,p-n)
    p = 0
    n = 0
    for i in range(N):
        if i <= (N//2)-1:
            p+=A[i]*2
        else:
            if i == (N//2) or i == (N//2)+1:
                n+=A[i]
            else:
                n+=A[i]*2
    MAX = max(MAX,p-n)
        
print(MAX)
