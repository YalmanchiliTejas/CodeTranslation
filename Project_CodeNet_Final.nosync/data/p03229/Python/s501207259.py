N = int(input())
A = [int(input()) for i in range(N)]
A = sorted(A)
h = N // 2
if N % 2 == 0:
    ans = sum(A[h:])*2 - sum(A[:h])*2 - A[h] + A[h-1]
else:
    ans1 = sum(A[h+1:])*2 - sum(A[:h+1])*2 + (A[h-1] + A[h])
    ans2 = sum(A[h:])*2 - sum(A[:h])*2 - (A[h] + A[h+1])
    ans = max(ans1, ans2)
print(ans)