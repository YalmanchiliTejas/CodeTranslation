N = int(input())
A = [int(input()) for i in range(N)]
A.sort()

if N%2 == 0:
  S = A[:N//2]
  L = A[N//2:]
  ans = 2*sum(L)-L[0]-2*sum(S)+S[-1]
else:
  S1 = A[:N//2]
  L1 = A[N//2:]
  S2 = A[:N//2+1]
  L2 = A[N//2+1:]
  ans1 = 2*sum(L1)-L1[0]-L1[1]-2*sum(S1)
  ans2 = 2*sum(L2)-2*sum(S2)+S2[-1]+S2[-2]
  ans = max(ans1,ans2)
print(ans)