n = int(input())
a = []
for _ in range(n):
    a.append(int(input()))
a.sort(reverse=True)

cand1 = 2 * sum(a[:n//2-1]) + a[n//2-1] \
        + (1 if n%2 else -1) * a[n//2] - 2 * sum(a[n//2+1:])
cand2 = 2 * sum(a[:(n-1)//2]) + (-1 if n%2 else 1) * a[(n-1)//2] \
        - a[(n-1)//2+1] - 2 * sum(a[(n-1)//2+2:])
print(max(cand1, cand2))
