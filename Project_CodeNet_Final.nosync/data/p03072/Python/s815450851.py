n = int(input())
h = list(map(int, input().split()))
cn = 0
for i in range(n):
    cn += 1 if max(h[:i+1]) == h[i] else 0
print(cn)