N = int(input())
As = list(map(int, input().split()))
S = 0
T = 0
for i in range(N):
  S += As[i]
  T += (As[i] * As[i]) % 1000000007
# print(S)
# print(T)
A = S*S % 1000000007
B = T % 1000000007
X = (A - B) % 1000000007

print((X * int((1000000007 + 1)/2)) % 1000000007)