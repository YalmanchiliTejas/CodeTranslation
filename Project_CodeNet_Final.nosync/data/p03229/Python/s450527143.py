N = int(input())
A = [int(input()) for i in range(N)]
B = sorted(A)
H = N//2
if N%2==0:
    ans = -2*sum(B[:H-1]) -B[H-1] +B[H] +2*sum(B[H+1:])
    print(ans)
else:
    ans1 = -2*sum(B[:H-1]) -B[H-1] -B[H] +2*sum(B[H+1:])
    ans2 = -2*sum(B[:H]) +B[H] + B[H+1] +2*sum(B[H+2:])
    print(max(ans1, ans2))