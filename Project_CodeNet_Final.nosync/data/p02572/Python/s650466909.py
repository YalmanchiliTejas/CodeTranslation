N = int(input())
A = list(map(int, input().split()))
sumlist = [0]
for i in range(N-1):
  sumlist.append(sumlist[i]+A[N-1-i])
ans = 0
for i in range(N-1):
  ans += A[i]*sumlist[N-1-i]
print(ans%(1000000007))