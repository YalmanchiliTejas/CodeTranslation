N = int(input())
H = list(input().split())
h = [int(s) for s in H]
n = 1
for i in range(1, N):
    if h[i] == max(h[0:i+1]):
        n = n+1
print(n)