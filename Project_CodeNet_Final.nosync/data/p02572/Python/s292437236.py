M = 1000000007
n = int(input())
a = list(map(int,input().split()))
S = [0]
for i in range(n):
 S.append((S[-1]+a[i])%M)
sum = 0
for i in range(n-1):
 sum += (a[i]*(S[n]-S[i+1]))%M
print(sum%M)