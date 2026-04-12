# A = [list(map(int, input().split())) for _ in range(3)]
# n = int(input())
# B = [int(input()) for _ in range(n)]
# X = list(map(int, input().split()))
# n, m = map(int, input().split())
S = list(input())
if S[0] != S[1] or S[1] != S[2]:
    print("Yes")
else:
    print("No")
