N = int(input())
S = input()
K = int(input())

booked = S[K-1]
for s in S:
    print(s if s == booked else '*', end='')