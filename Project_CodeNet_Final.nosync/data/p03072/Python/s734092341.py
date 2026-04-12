import sys
input = sys.stdin.readline

n = int(input())

h_lis = list(map(int, input().split()))

lis = [h_lis[0]]

ans = []

for x in h_lis:
    if (x >= max(lis)):
        ans.append(x)
    lis.append(x)

print(len(ans))
